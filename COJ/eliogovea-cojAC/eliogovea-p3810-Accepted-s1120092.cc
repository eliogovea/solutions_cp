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

const int INV2 = power(2, MOD - 2);
const int INV3 = power(3, MOD - 2);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	long long n;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> n;
		long long x = n / 2LL + 1;
		x %= MOD;
		n %= MOD;
		int a = mul(x, INV2);
		int b = mul(n, mul(n + 1, mul(n + 2, INV3)));
		int c = mul(x - 1 + MOD, mul(x, mul(x + 1, INV3)));
		int d = mul(n - x + 1 + MOD, mul(x - 1 + MOD, mul(x, INV2)));
		int ans = b;
		add(ans, MOD - c);
		ans = mul(ans, a);
		add(ans, MOD - d);
		cout << "Case #" << cas << ": " << ans << "\n";
	}
}
