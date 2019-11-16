#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

int n, m;
vector <int> e[N];
vector <int> g[N];

bool visited[N];

int dfs(int u) {
	visited[u] = true;
	int s = 1;
	for (auto v : g[u]) {
		if (!visited[v]) {
			s += dfs(v);
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int r = 0; r < m; r++) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			x--;
			e[x].push_back(r);
		}
	}

	for (int c = 0; c < n; c++) {
		g[e[c][0]].push_back(e[c][1]);
		g[e[c][1]].push_back(e[c][0]);
	}

	int ans = 0;

	for (int c = 0; c < m; c++) {
		if (!visited[c]) {
			ans += dfs(c) - 1;	
		}
	}

	cout << ans << "\n";
}