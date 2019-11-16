#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int c, n, dp[1 << MAXN][MAXN], len[MAXN], sol;
char str[1000], ini[MAXN], fin[MAXN];

int main()
{
	for (scanf("%d", &c); c--;)
	{
		scanf("%d", &n);
		sol = 0;

		for (int mask = 1; mask < (1 << n); mask++)
			for (int i = 0; i < n; i++) dp[mask][i] = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			len[i] = strlen(str);
			ini[i] = str[0];
			fin[i] = str[len[i] - 1];
			dp[1 << i][i] = len[i];
			sol = max(sol, dp[1 << i][i]);
		}
		for (int mask = 1; mask < (1 << n); mask++)
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					for (int j = 0; j < n; j++)
						if (!(mask & (1 << j)) && fin[i] == ini[j])
						{
							dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + len[j]);
							sol = max(sol, dp[mask | (1 << j)][j]);
						}
		printf("%d\n", sol);
	}
}
