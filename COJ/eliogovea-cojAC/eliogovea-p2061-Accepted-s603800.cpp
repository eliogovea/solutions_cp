#include <cstdio>

typedef long long ll;

const ll mod = 1000000007;

int tc;
ll x, n;

ll exp(ll b, ll e) {
	if (e == 1ll) return b % mod;
	if (e & 1ll) return (b * exp(b, e - 1)) % mod;
	ll x = exp(b, e / 2) % mod;
	return (x * x) % mod;
}

ll solve(int x, int n) {
	return (((exp(x, n + 1ll) - 1ll + mod) % mod) * exp(x - 1ll, mod - 2ll)) % mod;
}

int main() {
	for (scanf("%d", &tc); tc--;) {
		scanf("%lld%lld", &x, &n);
		if (x == 1ll)printf("%lld\n", (n + 1ll) % mod);
		else printf("%lld\n", solve(x, n));
	}
}
