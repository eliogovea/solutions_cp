#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

const int N = 105;

int n, m, source, sink;

vector <pair <int, int> > g[N];

priority_queue <pair <int, int> > pq;

vector <int> dijkstra(int s) {
	vector <int> dist(n + 5, INF);
	vector <bool> mark(n + 5, false);
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (mark[u]) continue;
		mark[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first;
			int d = g[u][i].second;
			if (dist[v] > dist[u] + d) {
				dist[v] = dist[u] + d;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
	return dist;
}

const int M = 10005;

int ady[M], cap[M], flow[M], next[M], last[N], now[N];
int E;

void add(int a, int b) {
	ady[E] = b; cap[E] = 1; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

int depth[N];

int Q[N], qh, qt;

bool bfs() {
	qh = qt = 0;
	Q[qt++] = source;
	for (int i = 1; i <= n; i++) depth[i] = -1;
	depth[source] = 0;
	while (qh != qt) {
		int u = Q[qh++];
		for (int e = last[u]; e != -1; e = next[e]) {
			if (cap[e] > flow[e]) {
				int v = ady[e];
				if (depth[v] == -1) {
					depth[v] = depth[u] + 1;
					Q[qt++] = v;
				}
			}
		}
	}
	return (depth[sink] != -1);
}

int dfs(int u, int f) {
	if (u == sink) return f;
	for (int e = now[u]; e != -1; e = now[u] = next[e]) {
		if (cap[e] > flow[e]) {
			int v = ady[e];
			if (depth[v] == depth[u] + 1) {
				int ff = min(f, cap[e] - flow[e]);
				int push = dfs(v, ff);
				if (push != 0) {
					flow[e] += push;
					flow[e ^ 1] -= push;
					return push;
				}
			}
		}
	}
	return 0;
}

int max_flow() {
	int res = 0;
	while (bfs()) {
		for (int i = 1; i <= n; i++) now[i] = last[i];
		while (true) {
			int tmp = dfs(source, INF);
			if (tmp == 0) break;
			res += tmp;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> m >> source >> sink;
	for (int i = 0, x, y, z; i < m; i++) {
		cin >> x >> y >> z;
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}
	vector <int> dsource = dijkstra(source);
	vector <int> dsink = dijkstra(sink);

	for (int i = 1; i <= n; i++) {
		last[i] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int to = g[i][j].first;
			int d = g[i][j].second;
			if (dsource[i] + d + dsink[to] == dsource[sink]) {
				add(i, to);
			}
		}
	}

	cout << max_flow() << "\n";
}
