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
	const string ans[] = {"", "0 0", "-1 0", "0 1", "1 0"};
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		if (n <= 4) {
			cout << ans[n] << "\n";
			continue;
		}
		long long lo = 0;
		long long hi = 1;
		while (4LL * (hi + 1LL) * (hi + 1LL) < n) {
			hi *= 2LL;
		}
		long long k = lo;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2LL;
			if (4LL * (mid + 1LL) * (mid + 1LL) < n) {
				k = mid;
				lo = mid + 1LL;
			} else {
				hi = mid - 1LL;
			}
		}
		n -= 4LL * (k + 1LL) * (k + 1LL);
		long long x = 1LL + 2LL * k + 1LL;
		long long y = -k - 1LL;

		long long a = 3LL + 4LL * k;
		long long b = 2LL + 2LL * k;

		if (n <= a + 2LL) {
			x -= (n - 1LL);
		} else if (n <= a + 2LL + b + 1LL) {
			x -= (a + 2LL);
			n -= (a + 2LL);
			x += (n - 1LL);
			y += (n - 1LL);
		} else {
			x -= (a + 2LL);
			x += (b + 1LL);
			y += (b + 1LL);
			n -= (a + 2LL);
			n -= (b + 1LL);
			x += (n - 1LL);
			y -= (n - 1LL);
		}
		cout << x << " " << y << "\n";
	}
}
