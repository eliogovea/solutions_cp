#include <cstdio>

typedef long long ll;

const ll mod = 1000000007, MAXN = 2010;

int n;
ll c[MAXN][MAXN], f[MAXN], sol;

ll cmb(int n, int p) {
	if (p > n - p) p = n - p;
	if (p == 0) return 1;
	if (c[n][p]) return c[n][p];
	return c[n][p] = (cmb(n - 1, p - 1) + cmb(n - 1, p)) % mod;
}

int main() {
	scanf("%d", &n);
	f[0] = 1ll;
	for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * (ll)i) % mod;
	for (int i = 0; i <= n; i++)
		if (!(i & 1)) sol = (sol + (cmb(n, i) * f[n - i]) % mod) % mod;
		else sol = (sol - ((cmb(n, i) * f[n - i]) % mod) + mod) % mod;
	printf("%lld\n", sol);
}

