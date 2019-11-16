#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 250000;
const ll mod = 5000011;

int n, k;
ll fact[MAXN + 5], inv_fact[MAXN + 5], sol = 1;

ll power(ll x, ll nn) {
	ll r = 1ll;
	while (nn) {
		if (nn & 1ll) r = (r * x) % mod;
		x = (x * x) % mod;
		nn >>= 1ll;
	}
	return r;
}

ll comb(int n, int p) {
  if (p > n || n <= 0) return 0;
  if (p == 0 || p == n) return 1;
	ll r = fact[n];
	r *= inv_fact[p]; r %= mod;
	r *= inv_fact[n - p]; r %= mod;
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	fact[0] = 1;
	for (ll i = 1; i <= MAXN; i++)
		fact[i] = (i * fact[i - 1]) % mod;
	for (ll i = 1; i <= MAXN; i++)
		inv_fact[i] = power(fact[i], mod - 2);

	for (int i = 1; k * (i - 1) + i <= n; i++)
		sol = (sol + comb(n - k * (i - 1), i)) % mod;
	cout << sol << "\n";
}
