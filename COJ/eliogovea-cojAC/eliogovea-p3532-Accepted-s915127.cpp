#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

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

int f[N];

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p, k;
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = mul(f[i - 1], i);
	}
	cin >> n >> p >> k;
	int ans = 0;
	for (int i = 0; i * p <= n; i++) {
		int x = n - i * p;
		if (x % k) {
			continue;
		}
		int y = x / k;
		//cout << i << " " << y << " " << mul(f[i + y], power(mul(f[i], f[y]), MOD - 2)) << "\n";
		add(ans, mul(f[i + y], power(mul(f[i], f[y]), MOD - 2)));
		//cout << i << " " << ans << "\n";
	}
	cout << ans << "\n";
}
