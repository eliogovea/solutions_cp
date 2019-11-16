#include <cstdio>
#include <cstring>

typedef long long ll;

char n[100005];
ll c, m, sol;

inline ll pow(ll x, ll n, ll m) {
	ll r = 1ll;
	while (n) {
		if (n & 1ll) r = (r * x) % m;
		x = (x * x) % m;
		n >>= 1ll;
	}
	return r;
}

int main() {
	while (scanf("%s%lld%lld", n, &c, &m) != EOF) {
		sol = 1ll;
		c %= m;
		int l;
		for (l = 0; n[l]; l++);
		for (int i = l - 1; i >= 0; i--) {
			sol = (sol * pow(c, n[i] - '0', m)) % m;
			c = pow(c, 10, m);
		}
		printf("%lld\n", sol);
	}
	return 0;
}
