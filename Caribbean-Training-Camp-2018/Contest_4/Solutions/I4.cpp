#include <bits/stdc++.h>

using namespace std;

typedef double LD;

const int M = 1053818881;

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

int root[50];
int invRoot[50];

bool ready = false;

void calcRoot() {
	int a = 2;
	while (power(a, (M - 1) / 2) != M - 1) {
		a++;
	}
	int l = 1;
	int e = 0;
	while ((M - 1) % l == 0) {
		root[e] = power(a, (M - 1) / l);
		invRoot[e] = power(root[e], M - 2);
		l <<= 1;
		e++;
	}
	ready = true;
}

void fft(vector <int> & P, bool invert) {
	assert(ready);
	int n = P.size();
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


void fft(vector <vector <int> > & P, bool invert) {
	int n = P.size();
	int m = P[0].size();
	for (int r = 0; r < n; r++) {
		fft(P[r], invert);
	}
	for (int c = 0; c < m; c++) {
		vector <int> Q(n);
		for (int r = 0; r < n; r++) {
			Q[r] = P[r][c];
		}
		fft(Q, invert);
		for (int r = 0; r < n; r++) {
			P[r][c] = Q[r];
		}
	}
}

inline int fix(int n) {
	int x = 1;
	while (x < n) {
		x <<= 1;
	}
	x <<= 1;
	return x;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector <string> s(n);
	for (auto & x : s) {
		cin >> x;
	}

	int ln = fix(n);
	int lm = fix(m);

	vector <vector <int> > P(ln, vector <int> (lm));
	vector <vector <int> > Q(ln, vector <int> (lm));

	int t = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				t++;
				P[i][j] = 1;
				Q[n - 1 - i][m - 1 - j] = 1;
			}
		}
	}

	assert(t >= 3);

	calcRoot();
	
	fft(P, false);
	fft(Q, false);
	for (int i = 0; i < ln; i++) {
		for (int j = 0; j < lm; j++) {
			P[i][j] = mul(P[i][j], Q[i][j]);
		}
	}
	fft(P, true);

	LD e = 0;

	for (int x = 0; x < 2 * n - 1 ; x++) {
		for (int y = 0; y < 2 * m - 1; y++) {
			int xx = x - (n - 1);
			int yy = y - (m - 1);
			
			if (xx < 0 || (xx == 0 && yy < 0)) {
				continue;
			}

			if (xx == 0 && yy == 0) {
				continue;
			}

			int cnt = P[x][y]; 
			LD len = sqrt((LD)(xx * xx + yy * yy));
				
//			if (cnt > 0) {
//			cerr << xx << " " << yy << " " << cnt << " " << len << "\n";
//			}
			e += len * (LD)P[x][y];
		}
	}


	e *= (LD)6.0;
	e /= (LD)((long long)t * (t - 1LL));

	cout << fixed << e << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(17);

	solve();
}
