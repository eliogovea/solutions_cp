#include <cstdio>

typedef long long ll;

const ll mod = 1000003, MAXN = 1000;

ll c[MAXN + 5][MAXN + 5], sol[MAXN + 5], n;

int main() {
	for (int i = 0; i <= MAXN; i++)
		c[i][0] = c[i][i] = 1ll;
	for (int i = 2; i <= MAXN; i++)
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	sol[0] = 1ll;
	for (int i = 1; i <= MAXN; i++)
		for (int j = 1; j <= i; j++)
			sol[i] = (sol[i] + (c[i][j] * sol[i - j]) % mod) % mod;
	while (scanf("%d", &n) && n) printf("%lld\n", sol[n]);
}
