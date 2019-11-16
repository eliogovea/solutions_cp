#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

int n, m, s;
vector <int> g[N];
int p[N];
bool vis[N];
int depth[N];
bool possible[N];
pair <int, int> st[N];
int top;

void dfs(int u, int f = -1, int d = 0) {
	p[u] = f;
	depth[u] = d;
	vis[u] = true;

	if (g[u].size() == 1 && f != -1) {
		possible[u] = true;
	}

	for (auto v : g[u]) {
		if (v != f) {
			if (!vis[v]) {
				dfs(v, u, d + 1);
			} else if (depth[v] < d) {
				if (g[u].size() == 2) {
					possible[u] = true;
				}
				int x = u;
				while (p[x] != v) {
					x = p[x];
				}
				if (g[x].size() == 2) {
					possible[x] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> s;
	
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		possible[i] = false;
		g[i].clear();
	}
	
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

/*
	dfs(s);
	
	for (int i = 1; i <= n; i++) {
		if (possible[i]) {
			cerr << i << "\n";
		}
	}
	exit(0);
*/

	top = 0;
	st[top++] = make_pair(s, 0);
	p[s] = -1;
	vis[s] = true;
	depth[s] = 0;

	while (top > 0) {
		int u = st[top - 1].first;
		int & e = st[top - 1].second;

		if (e < g[u].size()) {
			int v = g[u][e++];

			if (v == p[u]) {
				continue;
			}

			if (!vis[v]) {
				p[v] = u;
				vis[v] = true;
				depth[v] = depth[u] + 1;

				if (g[v].size() == 1) {
					possible[v] = true;
				}

				st[top++] = make_pair(v, 0);
			} else if (depth[v] < depth[u]) {
				if (g[u].size() == 2) {
					possible[u] = true;
				}		
				int x = u;
				while (p[x] != v) {
					x = p[x];
				}
				if (g[x].size() == 2) {
					possible[x] = true;
				}
			}
		} else {
			top--;
		}

	}
/*
	for (int i = 1; i <= n; i++) {
		if (possible[i]) {
			cerr << i << "\n";
		}
	}
*/
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (possible[i]) {
			answer++;
		}
	}

	cout << answer << "\n";
}
