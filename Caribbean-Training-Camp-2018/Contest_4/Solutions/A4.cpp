#include <bits/stdc++.h>

using namespace std;

template <const int M>
struct FFT {
	vector <int> root;
	vector <int> invRoot;

	inline void add(int & a, int b) {
		a += b;
		if (a >= M) {
			a -= M;
		}
	}

	inline int mul(int a, int b) {
		return (long long)a * b % M;
	}

	inline int power(int x, int n) {
		int y = 1;
		while (n) {
			if (n & 1) {
				y = mul(y, x);
			}
			x = mul(x, x);
			n >>= 1;
		}
		return y;
	}

	void calcRoots() {
		int a = 2;
		while (power(a, (M - 1) / 2) != M - 1) {
			a++;
		}
		for (int l = 1; (M - 1) % l == 0; l <<= 1) {
			root.push_back(power(a, (M - 1) / l));
			invRoot.push_back(power(root.back(), M - 2));
		}
	}

	FFT() {
		calcRoots();
	}

	void transform(vector <int> & P, bool invert) {
		int n = P.size();
		assert((M - 1) % n == 0);

		int ln = 0;
		while ((1 << ln) < n) {
			ln++;
		}
		assert((1 << ln) == n);

		for (int i = 0; i < n; i++) {
			int x = i;
			int y = 0;
			for (int j = 0; j < ln; j++) {
				y = (y << 1) | (x & 1);
				x >>= 1;
			}
			if (y < i) {
				swap(P[y], P[i]);
			}
		}

		for (int e = 1; (1 << e) <= n; e++) {
			int len = (1 << e);
			int half = len >> 1;
			int step = root[e];
			if (invert) {
				step = invRoot[e];
			}
			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < half; j++) {
					int u = P[i + j];
					int v = mul(P[i + j + half], w);
					P[i + j] = u;
					add(P[i + j], v);
					P[i + j + half] = u;
					add(P[i + j + half], M - v);
					w = mul(w, step);
				}
			}
		}

		if (invert) {
			int in = power(n, M - 2);
			for (int i = 0; i < n; i++) {
				P[i] = mul(P[i], in);
			}
		}
	}

	void square(vector <int> & P) {
		transform(P, false);
		for (int i = 0; i < P.size(); i++) {
			P[i] = mul(P[i], P[i]);
		}
		transform(P, true);
	}

	vector <int> mul(vector <int> P, vector <int> Q) {
		int n = 1;
		while (n < P.size() + Q.size() - 1) {
			n <<= 1;
		}
		P.resize(n);
		Q.resize(n);
		transform(P, false);
		transform(Q, false);
		for (int i = 0; i < n; i++) {
			P[i] = mul(P[i], Q[i]);
		}
		transform(P, true);
		return P;
	}

	vector <int> add(const vector <int> & P, const vector <int> & Q) {
		vector <int> R(max(P.size(), Q.size()));
		for (int i = 0; i < R.size(); i++) {
			if (i < P.size()) {
				add(R[i], P[i]);
			}
			if (i < Q.size()) {
				add(R[i], Q[i]);
			}
		}
		return R;
	}

	void _mul(vector <int> & P, vector <int> Q) {
		// TODO
	}

	vector <int> inverse(vector <int> P, int m) {
		if (P[0] == 0) {
			return vector <int> ();
		}

		int c = power(P[0], M - 2);

		if (m == 1) {
			return vector <int> (1, c);
		}

		int n = 1;
		while (n < m) {
			n <<= 1;
		}


		P.resize(n);

		for (int i = 0; i < n; i++) {
			P[i] = mul(P[i], c);
		}

		vector <int> Q(n);
		Q[0] = 0;
		for (int i = 1; i < n; i++) {
			Q[i] = M - P[i];
			if (Q[i] == M) {
				Q[i] = 0;
			}
		}

		vector <int> R(1, 1);
		int e = 1;
		while (e < n) {
			assert(Q[0] == 0);
			Q[0] = 1;
			R = mul(R, Q);
			R.resize(n);
			Q[0] = 0;
			Q = mul(Q, Q);
			Q.resize(n);
			e <<= 1;
		}

		auto S = mul(R, P);

		assert(S[0] == 1);
		for (int i = 1; i < n; i++) {
			assert(S[i] == 0);
		}

		for (int i = 0; i < n; i++) {
			R[i] = mul(R[i], c);
		}
		R.resize(m);
		return R;
	}
};

static FFT <7340033> fft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector <int> P(n + 1);
	for (auto & x : P) {
		cin >> x;
	}

	P.resize(m);

	auto Q = fft.inverse(P, m);

	if (!Q.size()) {
		cout << "The ears of a dead donkey\n";
	} else {
		for (int i = 0; i < m; i++) {
			cout << Q[i];
			if (i + 1 < m) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
