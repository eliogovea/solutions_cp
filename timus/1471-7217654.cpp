// Problem: pace=1&num=1471
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int Q = 75005;

int n;
vector <pair <int, int> > g[N];

bool visited[N];

int nq;
int a[Q], b[Q];
int lca[Q];
vector <int> q[Q];

int leader[N];
int ancestor[N];

inline int findLeader(int u) {
	if (leader[u] != u) {
		leader[u] = findLeader(leader[u]);
	}
	return leader[u];
}

inline void unite(int u, int v, int _ancestor) {
	u = findLeader(u);
	v = findLeader(v);
	if (rand() & 1) {
		swap(u, v);
	}
	leader[u] = v;
	ancestor[v] = _ancestor;
}

int dist[N];

void dfs(int u, int p, int d) {
	visited[u] = true;
	leader[u] = u;
	ancestor[u] = u;
	dist[u] = d;

	for (int i = 0; i < q[u].size(); i++) {
		int id = q[u][i];
		int v;
		if (a[id] == u) {
			v = b[id];
		} else {
			v = a[id];
		}
		if (visited[v]) {
			lca[id] = ancestor[findLeader(v)];
		}
	}

	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].first;
		if (v == p) {
			continue;
		}
		dfs(v, u, d + g[u][i].second);
		unite(v, u, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back(make_pair(v, d));
		g[v].push_back(make_pair(u, d));
	}

	cin >> nq;
	for (int i = 0; i < nq; i++) {
		cin >> a[i] >> b[i];
		q[a[i]].push_back(i);
		q[b[i]].push_back(i);
	}

	dfs(0, -1, 0);

	for (int i = 0; i < nq; i++) {
		int answer = dist[a[i]] + dist[b[i]] - 2 * dist[lca[i]];
		cout << answer << "\n";
	}
}
