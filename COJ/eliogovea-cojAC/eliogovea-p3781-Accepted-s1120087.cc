#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("dat.txt", "r", stdin);

	int n, p;
	while (cin >> n >> p) {
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector <int> pref(n + 1);
		pref[0] = 1;
		for (int i = 1; i <= n; i++) {
			int val = power(p, a[i - 1]);
			add(val, 1);
			pref[i] = mul(pref[i - 1], val);

		}
		int q;
		cin >> q;
		while (q--) {
			int a, b;
			cin >> a >> b;
			int ans = mul(pref[b], power(pref[a - 1], MOD - 2));
			add(ans, MOD - 1);
			cout << ans << "\n";
		}
	}
}
