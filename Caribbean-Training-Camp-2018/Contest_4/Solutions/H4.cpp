#include <bits/stdc++.h>

using namespace std;

const int M = 7340033;

	vector <int> root;
	vector <int> invRoot;

	bool ready = false;

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
		ready = true;
		int a = 2;
		while (power(a, (M - 1) / 2) != M - 1) {
			a++;
		}
		for (int l = 1; (M - 1) % l == 0; l <<= 1) {
			root.push_back(power(a, (M - 1) / l));
			invRoot.push_back(power(root.back(), M - 2));
		}
	}

	void transform(vector <int> & P, int n, bool invert) {
		int ln = 0;
		while ((1 << ln) < n) {
			ln++;
		}

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

	vector <int> inverse(vector <int> P, int m) {
		if (P[0] == 0) {
			return vector <int> ();
		}

		int n = 1;
		while (n < P.size()) {
			n <<= 1;
		}

		P.resize(n);

		vector <int> Q(2 * n);
		vector <int> R(2 * n);
		vector <int> S(2 * n);

		R[0] = power(P[0], M - 2);
		for (int k = 2; k <= n; k *= 2) {
			for (int i = 0; i < k; i++) {
				S[i] = R[i];
			}
			for (int i = 0; i < min(k, n); i++) {
				Q[i] = P[i];
			}
			for (int i = min(k, n); i < 2 * k; i++) {
				Q[i] = 0;
			}
			transform(S, 2 * k, false);
			transform(Q, 2 * k, false);
			for (int i = 0; i < 2 * k; i++) {
				S[i] = mul(S[i], mul(S[i], Q[i]));
			}
			transform(S, 2 * k, true);
			for (int i = 0; i < k; i++) {
				add(R[i], R[i]);
				add(R[i], M - S[i]);
			}
		}

		return R;
	}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	calcRoots();

	int n;
	cin >> n;

	vector <int> P(n + 1);

	vector <int> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = mul(f[i - 1], i);
	}

	vector <int> invf(n + 1);
	invf[n] = power(f[n], M - 2);
	for (int i = n - 1; i >= 0; i--) {
		invf[i] = mul(invf[i + 1], i + 1);
	}

	P[0] = 1;
	P[1] = 1;
	for (int i = 2, x = 2; i <= n; i++) {
		P[i] = mul(P[i - 1], mul(x ,mul(f[i - 1], invf[i])));
		add(x, x);
	}


	auto Q = inverse(P, n + 1);
	for (int i = 0; i < Q.size(); i++) {
		Q[i] = M - Q[i];
		if (Q[i] == M) {
			Q[i] = 0;
		}
	}

	add(Q[0], 1);

	for (int i = 1; i <= n; i++) {
		cout << mul(Q[i], f[i]);
		if (i + 1 <= n) {
			cout << " ";
		}
	}
	cout << "\n";

}
