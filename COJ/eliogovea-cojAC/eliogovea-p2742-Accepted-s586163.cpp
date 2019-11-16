#include <cstdio>

const int MAXN = 1000, mod = 1000009;

int t, n, k, c[MAXN + 10][MAXN + 10], sol;

int cmb(int a, int b)
{
	if (b > a - b) b = a - b;
	if (b == 0) return 1;
	if (c[a][b]) return c[a][b];
	return c[a][b] = (cmb(a - 1, b - 1) + cmb(a - 1, b)) % mod;
}

int main()
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d%d", &n, &k);
		sol = 0;
		for (int i = n; i >= k; i--)
			sol = (sol + (i * cmb(i - 1, k - 1)) % mod) % mod;
		printf("%d\n", sol);
	}
}
