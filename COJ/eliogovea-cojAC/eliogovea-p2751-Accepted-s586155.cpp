#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 101010;

int n, m, k, dist[MAXN];
vector<int> G[MAXN];
queue<int> Q;

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1, x; i <= m; i++)
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &x);
			G[x].push_back(n + i);
			G[n + i].push_back(x);
		}
	for (int i = 1; i <= n + m; i++)
		dist[i] = 1 << 29;
	dist[1] = 0;
	Q.push(1);
	while (!Q.empty())
	{
		int act = Q.front();
		Q.pop();
		for (vector<int>::iterator it = G[act].begin(); it != G[act].end(); it++)
			if (dist[*it] == 1 << 29)
			{
				dist[*it] = dist[act] + 1;
				Q.push(*it);
			}
	}
	if (dist[n] == 1 << 29) printf("-1\n");
	else printf("%d\n", dist[n] / 2 + 1);
}
