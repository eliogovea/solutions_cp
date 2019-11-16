#include <bits/stdc++.h>

using namespace std;

int n, m, r, e;

vector <int> g[1005];

bool mark[1005];

int nodes, edges;

void dfs(int u) {
	mark[u] = true;
	nodes++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		edges++;
		if (!mark[v]) dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> m >> r >> e;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			nodes = 0;
			edges = 0;
			dfs(i);
			edges /= 2;
			//cout << nodes << " " << edges << " ";
			long long v1 = (long long)((long long)nodes * (nodes - 1LL) / 2LL - edges) * r;
			long long v2 = (long long)nodes * e;
			//cout << v1 << " " << v2 << "\n";
			ans += min(v1, v2);
		}
	}
	cout << ans << "\n";
}
