#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

const int N = 1000005;

int n, k;
ll f[N];

ll power(ll x, int n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int d = n - k;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (1LL * f[i - 1] * i) % mod;
	}
	ll ans = 0;
	ll sign = 1;
	for (int i = 0; i <= d; i++) {
		ans += sign * ((f[d] * power(f[i], mod - 2)) % mod);
		ans = (ans + mod) % mod;
		sign *= -1LL;
	}
	ans = (ans * f[n]) % mod;
	ans = (ans * power(f[k], mod - 2)) % mod;
	ans = (ans * power(f[n - k], mod - 2)) % mod;
	cout << ans << "\n";
}
