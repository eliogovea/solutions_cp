// Problem: pace=1&num=1752
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 20005;
const int LN = 15;

int n;
int q;

vector <int> g[N];

int parent[LN][N];

int timer;
int timeIn[N];
int timeOut[N];

int dist[N];

void dfs(int u, int p, int d) {
	timeIn[u] = timer++;
	dist[u] = d;
	parent[0][u] = p;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		dfs(v, u, d + 1);
	}
	timeOut[u] = timer++;
}

inline bool isAncestor(int u, int v) {
	return (timeIn[u] <= timeIn[v] && timeOut[v] <= timeOut[u]);
}

inline int getLCA(int u, int v) {
	if (isAncestor(u, v)) {
		return u;
	}
	for (int i = LN - 1; i >= 0; i--) {
		if (!isAncestor(parent[i][u], v)) {
			u = parent[i][u];
		}
	}
	return parent[0][u];
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, 0, 0);
	int x = 0;
	for (int i = 1; i < n; i++) {
		if (dist[i] > dist[x]) {
			x = i;
		}
	}
	dfs(x, x, 0);
	int y = 0;
	for (int i = 1; i < n; i++) {
		if (dist[i] > dist[y]) {
			y = i;
		}
	}

	for (int i = 1; i < LN; i++) {
		for (int j = 0; j < n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	while (q--) {
		int u, d;
		cin >> u >> d;
		u--;
		int answer = -1;
		if (dist[u] >= d) {
			answer = u;
			for (int i = 0; i < LN; i++) {
				if (d & (1 << i)) {
					answer = parent[i][answer];
				}
			}
		} else {
			int	z = getLCA(u, y);
			int tDist = dist[u] + dist[y] - 2 * dist[z];
			if (tDist >= d) {
				if (dist[u] - dist[z] >= d) {
					answer = u;
					for (int i = 0; i < LN; i++) {
						if (d & (1 << i)) {
							answer = parent[i][answer];
						}
					}
				} else {
					d = tDist - d;
					answer = y;
					for (int i = 0; i < LN; i++) {
						if (d & (1 << i)) {
							answer = parent[i][answer];
						}
					}
					d = tDist - d;
				}
			}
		}

		if (answer == -1) {
			cout << "0\n";
			continue;
		} else {
			{ // debug
				int z = getLCA(u, answer);
				assert(dist[u] + dist[answer] - 2 * dist[z] == d);
			}
			cout << answer + 1 << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
