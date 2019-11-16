#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int n, m, dp[MAXN + 10][MAXN + 10];

int main()
{
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = dp[i][1] = i;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++)
		for (int j = i + 1; j <= m; j++)
		{
			dp[i][j] = i * j;
			for (int k = 1; k <= i / 2; k++)
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
			for (int k = 1; k <= j / 2; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
			dp[j][i] = dp[i][j];
		}
	printf("%d\n", dp[n][m]);
}
