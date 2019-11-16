#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int n, m;
vector <int> g[N];
int match[N];
int visited[N], mark;

bool dfs(int u) {
	if (visited[u] == mark) {
		return false;
	}
	visited[u] = mark;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
		}
		for (int i = 0; i < n; i++) {
			match[i] = -1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			mark++;
			if (dfs(i)) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}
