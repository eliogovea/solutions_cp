#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;

ll power(ll x, ll n, ll m) {
	ll res = 1;
	x %= m;
	while (n) {
		if (n & 1LL) {
			res = (res * x) % m;
		}
		x = (x * x) % m;
		n >>= 1LL;
	}
	return res;
}

int n, k;

const int N = 1000005;

ll f[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = (f[i - 1] * (ll)i) % mod;
	}
	while (cin >> n >> k) {
		if (k > n - k) {
			k = n - k;
		}
		ll x = (power(2, n, mod - 1) - (n % (mod - 1)) + (mod - 1)) % (mod - 1);
		ll y = power(2, x, mod);
		if (k == 0) {
			cout << y << "\n";
			continue;
		}
		ll a = (f[n] * power(f[n - k], mod - 2, mod)) % mod;
		ll b = power(f[k], mod - 2, mod);
		ll c = (a * b) % mod;
		c = (y * c) % mod;
		cout << c << "\n";
	}
}
