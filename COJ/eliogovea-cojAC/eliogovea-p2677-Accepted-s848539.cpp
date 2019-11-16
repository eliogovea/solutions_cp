#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, k;
vector<int> g[N];
int match[N];
int used[N], ttt;

bool dfs(int u) {
	if (used[u] == ttt) return false;
	used[u] = ttt;
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
	cin >> n >> m >> k;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
	}
	for (int i = 0; i < n; i++) match[i] = -1;
	int ans = n;
	for (int i = 0; i < n; i++) {
		ttt++;
		if (dfs(i)) ans--;
	}
	cout << (ans <= k ? "YES" : "NO") << "\n";
}
