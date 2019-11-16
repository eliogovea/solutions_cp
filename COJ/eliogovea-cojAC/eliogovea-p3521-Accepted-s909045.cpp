#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int t;
long long n;

long long power(long long x, int n) {
	long long res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const long long x = power(3, MOD - 2);
	while (cin >> n) {
        n--;
		long long ans = n;
		ans = (ans * (n + 1LL)) % MOD;
		ans = (ans * (n + 2LL)) % MOD;
		ans = (ans * x) % MOD;
		cout << ans << "\n";
	}
}
