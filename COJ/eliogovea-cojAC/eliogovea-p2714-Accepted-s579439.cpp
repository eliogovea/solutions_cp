#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int t, n, m, q, G[MAXN][MAXN], a, b, c;

int main()
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				G[i][j] = G[j][i] = (i == j) ? 0 : 1 << 29;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = G[b][a] = min(G[a][b], c);
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					G[i][j] = G[j][i] = min(G[i][j], G[i][k] + G[k][j]);
		for (scanf("%d", &q); q--;)
		{
			scanf("%d%d", &a, &b);
			printf("%d\n", (G[a][b] == 1 << 29) ? -1 : G[a][b]);
		}
		if(t) printf("\n");
	}
}
