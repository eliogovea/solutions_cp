#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct edge {
	int from;
	int to;
	bool isbridge;
};

int n, m;
int vals[N];
edge E[6 * N];
vector <int> graph[N];

void read() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> E[2 * i].from;
		cin >> E[2 * i].to;
		E[2 * i].isbridge = false;
		graph[E[2 * i].from].push_back(2 * i);
		E[2 * i + 1].from = E[2 * i].to;
		E[2 * i + 1].to = E[2 * i].from;
		E[2 * i + 1].isbridge = false;
		graph[E[2 * i + 1].from].push_back(2 * i + 1);
	}
}

int visited[N];
int seen[N];
int timer;

void find_bridges(int u, int p) {
	if (visited[u] != -1) {
		return;
	}
	visited[u] = seen[u] = timer++;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = E[graph[u][i]].to;
		if (v == p) {
			continue;
		}
		if (visited[v] == -1) {
			find_bridges(v, u);
			seen[u] = min(seen[u], seen[v]);
			if (seen[v] > visited[u]) {
				E[graph[u][i]].isbridge = true;
				E[graph[u][i] ^ 1].isbridge = true;
			}
		} else {
			seen[u] = min(seen[u], visited[v]);
		}
	}
}

int tcomp;
int comp[N];
int compval[N];

void dfs(int u, int p) {
	comp[u] = tcomp;
	compval[tcomp] += vals[u];
	for (int i = 0; i < graph[u].size(); i++) {
		if (!E[graph[u][i]].isbridge) {
			int v = E[graph[u][i]].to;
			if ((v != p) && (comp[v] == -1)) {
				dfs(v, u);
			}
		}
	}
}

vector <int> G[N];

void calc_dist(int u, int p, int d, int *dist) {
	dist[u] = d;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) {
			continue;
		}
		calc_dist(v, u, d + compval[v], dist);
	}
}

int dist1[N], dist2[N];

void solve() {
	read();
	for (int i = 1; i <= n; i++) {
		visited[i] = seen[i] = -1;
	}
	find_bridges(1, -1);
	for (int i = 1; i <= n; i++) {
		comp[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (comp[i] == -1) {
            compval[tcomp] = 0;
			dfs(i, -1);
			tcomp++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int id = 0; id < graph[i].size(); id++) {
			if (E[graph[i][id]].isbridge) {
				int x = comp[i];
				int y = comp[E[graph[i][id]].to];
				G[x].push_back(y);
				//G[y].push_back(x);
			}
		}
	}

	calc_dist(0, -1, compval[0], dist1);
	int x = 0;
	for (int i = 0; i < tcomp; i++) {
		if (dist1[i] > dist1[x]) {
			x = i;
		}
	}
	calc_dist(x, -1, compval[x], dist1);
	int y = 0;
	for (int i = 0; i < tcomp; i++) {
		if (dist1[i] > dist1[y]) {
			y = i;
		}
	}
	calc_dist(y, -1, compval[y], dist2);
	for (int i = 1; i <= n; i++) {
		cout << max(dist1[comp[i]], dist2[comp[i]]);
		if (i + 1 <= n) {
			cout << " ";
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
