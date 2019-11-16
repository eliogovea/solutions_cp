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

const int INV2 = power(2, MOD - 2);
const int INV6 = power(6, MOD - 2);

int solve(int n) {
	int res = 0;
	add(res, mul(n + 1, mul(n, mul(n + 1, INV2))));
	add(res, MOD - mul(n, mul(n + 1, mul(2 * n + 1, INV6))));
	res = mul(res, res);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
}
