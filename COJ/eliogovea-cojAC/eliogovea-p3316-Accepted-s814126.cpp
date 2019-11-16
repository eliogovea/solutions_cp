#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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

int t;
ll K, m;
ll p[5000], k[5000];
ll pi[5000];
ll g[2000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> K >> m;
		ll res = 1;
		pi[0] = 1;
		ll ans = 1;
		for (int i = 1; i <= m; i++) {
			cin >> p[i] >> k[i];
			//pi[i] = (pi[i - 1] * power(p[i], k[i])) % mod;
			g[i] = (power(p[i], K * k[i]) - power(p[i], K * (k[i] - 1LL)) + mod) % mod;
			ans = (ans * g[i]) % mod;
		}
		cout << ans << "\n";
	}
}
