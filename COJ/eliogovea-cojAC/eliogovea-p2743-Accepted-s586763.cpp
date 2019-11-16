#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 55;

int c, n, m;
vector<int> G[MAXN];
bool mark[MAXN];
int in[MAXN], out[MAXN], deg[MAXN];

void dfs(int u)
{
	mark[u] = 1;
	for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
		if (!mark[*it]) dfs(*it);
}

int main()
{
    //freopen("e.in", "r", stdin);
    //freopen("e.out", "w", stdout);
	for (scanf("%d", &c); c--;)
	{
	    //printf("\n");
		scanf("%d%d", &n, &m);
		//printf("-->>%d %d\n", n, m);
		for (int i = 1; i <= n; i++)
		{
			in[i] = out[i] = deg[i] = mark[i] = 0;
			G[i].clear();

		}
		int s = 1;
		for (int i = 1, a, b; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			s = a;
			//printf("-->>%d %d\n", a, b);
			G[a].push_back(b);
			G[b].push_back(a);
			out[a]++;
			in[b]++;
			deg[a]++;
			deg[b]++;
		}
		dfs(s);
		bool con = true;
		for (int i = 1; i <= n; i++)
			if (!mark[i] && deg[i]) con = false;

		if (!con) printf("WAKE UP EARLIER\n");
		else
		{
			int mas = 0, menos = 0, imp = 0, sol = 1;
			for (int i = 1; i <= n; i++)
			{
				if (abs(out[i] - in[i]) > 1) sol = 0;
				if (out[i] - in[i] == 1) mas++;
				if (out[i] - in[i] == -1) menos++;

				if (deg[i] & 1) imp++;
			}
			if (sol && ((mas == 0 && menos == 0)
					|| (mas == 1 && menos == 1)) ) printf("YES\n");
			else if (imp == 0 || imp == 2) printf("TRAFFIC STOPPING NEEDED\n");
			else printf("WAKE UP EARLIER\n");
		}
	}
}
