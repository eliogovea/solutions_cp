#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

string s;
ll k;

ll power(ll x, ll n) {
	ll r = 1;
	while (n) {
		if (n & 1ll) r = (r * x) % mod;
		x = (x * x) % mod;
		n >>= 1ll;
	}
	return r;
}

ll solve() {
	ll sz = s.size();
	ll r = 0;
	for (int i = 0; s[i]; i++)
		if (s[i] == '0' || s[i] == '5') {
			ll a = power(2, i);
			ll b = power(2, sz);
			ll c = (power(b, k) - 1 + mod) % mod;
			ll d = power(b - 1, mod - 2);
			ll e = (a * c) % mod;
			e = (e * d) % mod;
			r = (r + e) % mod;
		}
	return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
	cin >> s >> k;
	cout << solve() << "\n";
}
