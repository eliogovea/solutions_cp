#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000007;

ll power(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1LL;
	}
	return res;
}

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> m >> n) {
        if (n == -1 && m == -1) {
            break;
        }
		ll a = (power(2, n + 1) - 1 + mod) % mod;
		ll b = (power(2, m) - 1 + mod) % mod;
		ll ans = (a - b + mod) % mod;
		cout << ans << "\n";
	}
}
