#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int val[N];
vector <int> g[N];

int vis[N], seen[N];
vector <pair <int, int> > bridges;
int timer;

void dfs1(int u, int p) {
	if (vis[u] != -1) {
		return;
	}
	vis[u] = seen[u] = timer++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		if (vis[v] == -1) {
			dfs1(v, u);
			seen[u] = min(seen[u], seen[v]);
			if (seen[v] > vis[u]) {
				bridges.push_back(make_pair(u, v));
				bridges.push_back(make_pair(v, u));
			}
		} else {
            seen[u] = min(seen[u], vis[v]);
		}
	}
}

int tcomp;
int comp[N];
int cval[N];


void dfs2(int u, int p) {
	comp[u] = tcomp;
	cval[tcomp] += val[u];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		int pos = lower_bound(bridges.begin(), bridges.end(), make_pair(u, v)) - bridges.begin();
		if (pos != bridges.size() && bridges[pos] == make_pair(u, v)) {
            continue;
		}
		if (v == p) {
			continue;
		}
		if (comp[v] == -1) {
			dfs2(v, u);
		}
	}
}

vector <int> g2[N];

void dfs3(int u, int p, int d, int *dist) {
    dist[u] = d;
	for (int i = 0; i < g2[u].size(); i++) {
		int v = g2[u][i];
		if (v == p) {
			continue;
		}
		dfs3(v, u, d + cval[v], dist);
	}
}

int dist1[N], dist2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
        cin >> val[i];
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = -1;
		seen[i] = -1;
		comp[i] = -1;
	}

	timer = 0;
	dfs1(1, -1);

	sort(bridges.begin(), bridges.end());

	for (int i = 1; i <= n; i++) {
		if (comp[i] == -1) {
			dfs2(i, -1);
			tcomp++;
		}
	}

	for (int i = 0; i < bridges.size(); i++) {
		int u = bridges[i].first;
		int v = bridges[i].second;
		int cu = comp[u];
		int cv = comp[v];
		g2[cu].push_back(cv);
		//g2[cv].push_back(cu);
	}

	dfs3(0, -1, cval[0], dist1);
	int x = 0;
	for (int i = 0; i < tcomp; i++) {
		if (dist1[i] > dist1[x]) {
			x = i;
		}
	}
	dfs3(x, -1, cval[x], dist1);
	int y = 0;
	for (int i = 0; i < tcomp; i++) {
		if (dist1[i] > dist1[y]) {
			y = i;
		}
	}
	dfs3(y, -1, cval[y], dist2);
	for (int i = 1; i <= n; i++) {
		cout << max(dist1[comp[i]], dist2[comp[i]]);
		if (i + 1 <= n) {
			cout << " ";
		}
	}
	cout << "\n";
	return 0;
}
