#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

typedef long double LD;

inline LD power(LD x, int n) {
	LD res = 1;
	while (n) {
		res *= x;
		n--;
	}
	return res;
}

const int N = 100005;

int t;
int n;
int x[N], y[N], p[N];

LD solve(int n, int *x, int *p) {
	LD lo = x[0];
	LD hi = x[0];
	for (int i = 1; i < n; i++) {
		lo = min(lo, (LD)x[i]);
		hi = max(hi, (LD)x[i]);
	}
	const int T = 350;
	for (int it = 0; it < T; it++) {
		LD d = (hi - lo) / 3.0;
		LD a = lo + d;
		LD b = hi - d;
		LD fa = 0.0;
		LD fb = 0.0;
		for (int i = 0; i < n; i++) {
			fa += power(abs(a - (LD)x[i]), p[i]);
			fb += power(abs(b - (LD)x[i]), p[i]);
		}
		if (fa < fb) {
			hi = b;
		} else {
			lo = a;
		}
	}
	LD val = (lo + hi) / 2.0;
	LD res = 0.0;
	for (int i = 0; i < n; i++) {
		res += power(abs(val - (LD)x[i]), p[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i] >> p[i];
		}
		LD ans = solve(n, x, p) + solve(n, y, p);
		cout << fixed << ans << "\n";
	}
}
