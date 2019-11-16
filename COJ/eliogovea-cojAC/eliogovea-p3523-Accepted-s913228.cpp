#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int power(int x, int n) {
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
const int INV4 = power(4, MOD - 2);

int solve(long long n) {
	int x = n % MOD;
	int y = x;
	int res = MOD - mul(x, INV2);
	y = mul(y, x);
	add(res, MOD - mul(y, INV4));
	y = mul(y, x);
	add(res, mul(y, INV2));
	y = mul(y, x);
	add(res, mul(y, INV4));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	long long n;
	while (cin >> n) {
		cout << solve(n) << "\n";
	}
}
