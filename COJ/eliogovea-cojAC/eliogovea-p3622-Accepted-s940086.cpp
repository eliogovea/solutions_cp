#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, m;
vector <int> g[N];
int depth[N];
bool ok = true;

void dfs(int u, int p, int d) {
	depth[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		if (depth[v] == -1) {
			dfs(v, u, d + 1);
		} else if (depth[v] < depth[u]) {
			if ((depth[u] - depth[v] + 1) % 3) {
				ok = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		depth[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (depth[i] == -1) {
			dfs(i, -1, 0);
		}
	}
	cout << (ok ? "yes" : "no") << "\n";
}
