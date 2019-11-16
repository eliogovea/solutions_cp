#include <cstdio>

typedef long long ll;

const int MAXN = 1000000;
const ll mod = 1000000007;

ll n;

ll exp(ll x, ll n) {
	ll r = 1ll;
	while (n) {
		if (n & 1ll) r = (r * x) % mod;
		x = (x * x) % mod;
		n >>= 1ll;
	}
	return r;
}

int main() {
	while (scanf("%lld", &n) && n) printf("%lld\n", (exp(2ll, n + 1ll) - 1ll + mod) % mod);
}
