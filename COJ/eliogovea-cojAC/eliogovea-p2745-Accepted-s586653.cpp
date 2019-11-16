#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXK = 310, MAXN = 100010;

int n, m, k, G[MAXK][MAXK], t[MAXK], tip[MAXN], ini[MAXK], fin[MAXK];
int used[MAXN], id;
vector<int> ady[MAXN];

void dfs(int u)
{
	used[u] = id;
	for (vector<int>::iterator it = ady[u].begin(); it != ady[u].end(); it++)
		if (used[*it] != id) dfs(*it);
}


int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, a = 1; i <= k; i++)
	{
		scanf("%d", t + i);
		ini[i] = a;
		for (int j = a; j < a + t[i]; j++)
			tip[j] = i;
		a += t[i];
		fin[i] = a;
	}

	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			if (i != j) G[i][j] = 1 << 29;

	for (int i = 1, x, y, z; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (tip[x] != tip[y])
			G[tip[x]][tip[y]] = G[tip[y]][tip[x]] = min(G[tip[x]][tip[y]], z);
		if (z == 0)
		{
			ady[x].push_back(y);
			ady[y].push_back(x);
		}
	}

	for (int i = 1; i <= k; i++)
	{
		id++;
		dfs(ini[i]);
		bool sol = true;
		for (int j = ini[i]; j < fin[i]; j++)
			if (used[j] != id) {printf("No\n"); return 0;}
	}
    printf("Yes\n");
	for (int l = 1; l <= k; l++)
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <=k; j++)
			G[i][j] = G[j][i] = min(G[i][j], G[i][l] + G[l][j]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			printf("%d%c", (G[i][j] == 1 << 29) ? -1 : G[i][j], (j == k) ? '\n' : ' ');
}
