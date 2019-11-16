#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

int n, m, s, t[MAXN], mx;
vector<int> G[MAXN], sol;

void dfs(int u)
{
	for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		t[*it] = t[u] + G[u].size();
		mx = max(mx, t[*it]);
		dfs(*it);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, a, b; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
	}
	scanf("%d", &s);
	dfs(s);
	for (int i = 1; i <= n; i++)
		if (t[i] == mx) sol.push_back(i);
	printf("%d\n", mx);
	for (int i = 0; i < sol.size(); i++)
		printf("%d%c", sol[i], (i != (int)sol.size() - 1) ? ' ' : '\n');
}
