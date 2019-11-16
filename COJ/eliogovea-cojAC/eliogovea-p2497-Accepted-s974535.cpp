#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int N = 15;

int t;
int n;
int p[N + 5], e[N + 5];

int x[(1 << N) + 5];
int y[(1 << N) + 5];
int cnt[(1 << N) + 5];

map <int, int> pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < N; i++) {
		pos[1 << i] = i;
	}
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> e[i];
		}
		x[0] = y[0] = cnt[0] = 1;
		for (int mask = 1; mask < (1 << n); mask++) {
			int last = pos[mask & -mask];
			x[mask] = mul(x[mask ^ (mask & -mask)], power(p[last], e[last]));
			y[mask] = mul(y[mask ^ (mask & -mask)], mul(power(p[last], e[last]) - 1, power(p[last] - 1, MOD - 2)));
			cnt[mask] = mul(cnt[mask ^ (mask & -mask)], e[last] + 1);
		}
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			int rmask = mask ^ ((1 << n) - 1);
			add(ans, mul(x[mask], mul(y[rmask], cnt[mask])));
		}
		int val = 1;
		for (int i = 0; i < n; i++) {
			val = mul(val, power(p[i], e[i]));
		}
		add(ans, val);
		cout << "Case " << cas << ": " << ans << "\n";
	}
}
