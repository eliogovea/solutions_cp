#include <bits/stdc++.h>

using namespace std;

const int MOD = (1 << 27) + (1 << 25) + 1;

inline int power(int x, int n) {
	int res = 1;
	while (n)  {
		if (n & 1) res = (long long)res * x % MOD;
		x = (long long)x * x % MOD;
		n >>= 1;
	}
	return res;
}

int roots[50], invRoots[50];

void calcRoots() { // !!!
	int a = 2;
	while (power(a, (MOD - 1) / 2) != MOD - 1) a++;
	for (int l = 1, e = 0; (MOD - 1) % l == 0; l *= 2, e++) {
		roots[e] = power(a, (MOD - 1) / l);
		invRoots[e] = power(roots[e], MOD - 2);
	}
}

void fft(vector <int> &P, bool invert) {
	int n = P.size();
	assert((n > 0) && (n == (n & -n)) && ((MOD - 1) % n == 0));
	int ln = 0;
	while ((1 << ln) < n) ln++;
	for (int i = 0; i < n; i++) {
		int x = i;
		int y = 0;
		for (int j = 0; j < ln; j++) {
			y = (y << 1) | (x & 1);
			x >>= 1;
		}
		if (y < i) swap(P[i], P[y]);
	}
	for (int l = 2, e = 1; l <= n; l *= 2, e++) {
		int hl = l >> 1;
		int step = roots[e];
		if (invert) step = invRoots[e];
		for (int i = 0; i < n; i += l) {
			int w = 1;
			for (int j = 0; j < hl; j++) {
				int u = P[i + j];
				int v = (long long)P[i + j + hl] * w % MOD;
				P[i + j] = (u + v) % MOD;
				P[i + j + hl] = (u - v + MOD) % MOD;
				w = (long long)w * step % MOD;
			}
		}
	}
	if (invert) {
		int in = power(n, MOD - 2);
		for (int i = 0; i < n; i++)
			P[i] = (long long)P[i] * in % MOD;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int N = 200 * 1000 + 1;
	int sz = 1;
	while (sz <= 2 * N) {
		sz <<= 1;
	}
	int n;
	cin >> n;

	vector <int> p(sz);
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		p[k] = 1;
	}
	p[0] = 1;
	calcRoots();
	fft(p, false);
	for (int i = 0; i < sz; i++) {
		p[i] = (long long)p[i] * p[i] % MOD;
	}
	fft(p, true);
	int ans = 0;
	int m;
	cin >> m;
	for (int i = 0, d; i < m; i++) {
		cin >> d;
		if (p[d] != 0) {
			// cerr<< "ok: " << d << "\n";
			ans++;
		}
	}
	cout << ans << "\n";
}