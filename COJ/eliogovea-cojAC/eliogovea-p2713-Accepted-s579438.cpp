
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 55;

int c, n, l, q, t[MAXN], a, b;
vector<int> G[MAXN];
queue<int> Q;

int main()
{
	for (scanf("%d", &c); c--;)
	{
		scanf("%d%d%d", &n, &l, &q);
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			t[i] = 0;
		}

		for (int i = 0; i < l; i++)
		{
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
		}

		t[1] = 1;
		Q.push(1);
		while (!Q.empty())
		{
			a = Q.front();
			Q.pop();
			for (int i = 0; i < G[a].size(); i++)
				if (!t[G[a][i]])
				{
					t[G[a][i]] = t[a] + 1;
					Q.push(G[a][i]);
				}
		}
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &a);
			printf("%d\n", (t[a]) ? t[a] : -1);
		}

	}
}
