#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int n, m;
vector<int> ady[N];
vector<int> cost[N];
pair<int, pair<int, int> > arc[250005];

vector<int> dist[2];
vector<bool> used;
priority_queue<pair<int, int> > Q;

void dijkstra(int s, vector<int> &d) {
	d.resize(n + 5);
	used.resize(n + 5);
	for (int i = 1; i < n; i++) {
		d[i] = 1 << 29;
		used[i] = false;
	}
	d[s] = 0;
	Q.push(make_pair(0, s));
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (used[u]) {
			continue;
		}
		used[u] = true;
		for (int i = 0; i < ady[u].size(); i++) {
			int v = ady[u][i];
			int w = cost[u][i];
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push(make_pair(-d[v], v));
			}
		}
	}
}

int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arc[i] = make_pair(w, make_pair(u, v));
		ady[u].push_back(v);
		cost[u].push_back(w);
		ady[v].push_back(u);
		cost[v].push_back(w);
	}
	dijkstra(0, dist[0]);
	dijkstra(n - 1, dist[1]);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		u = arc[i].second.first;
		v = arc[i].second.second;
		w = arc[i].first;
		if (dist[0][u] > dist[0][v]) {
			swap(u, v);
		}
		if (dist[0][n - 1] == dist[0][u] + w + dist[1][v]) {
			ans += 2 * w;
		}
	}
	cout << ans << "\n";
}
