#include <cstdio>

const int MAXN = 1005, MAXK = 205;

int n, k, a[MAXN][MAXN], dp[MAXK][MAXN], sol;
/// dp[i][j] guardo la mejor solucion tal que hay i gondolas
/// y termina en la posicion j

inline int get(int i1, int j1, int i2, int j2) {
	return (a[i2][j2] - a[i2][j1 - 1] - a[i1 - 1][j2] + a[i1 - 1][j1 - 1]) >> 1;
}

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}

	for (int i = 1; i <= n; i++)
		dp[1][i] = get(1, 1, i, i);
	sol = dp[1][n];
	for (int i = 2, x, y; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			x = 1 << 29;
			for (int k = i; k <= j; k++) {
				y = dp[i - 1][k - 1] + get(k, k, j, j);
				if (y < x) x = y;
			}
			dp[i][j] = x;
		}
		if (sol > dp[i][n]) sol = dp[i][n];
	}
	printf("%d\n", sol);
}
