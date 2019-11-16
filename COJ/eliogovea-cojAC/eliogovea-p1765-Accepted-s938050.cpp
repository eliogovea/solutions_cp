#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAXV = 250;
const int MAXE = 2 * MAXV * MAXV;

int source;
int sink;
int tnodes;
int tedges;
int from[MAXE];
int to[MAXE];
int cap[MAXE];
int flow[MAXE];
int next[MAXE];
int last[MAXV];
int now[MAXV];
int depth[MAXV];

int Q[MAXV], qh, qt; // queue

inline void addEdge(int a, int b, int c) {
	from[tedges] = a;
	to[tedges] = b;
	cap[tedges] = c;
	flow[tedges] = 0;
	next[tedges] = last[a];
	last[a] = tedges++;
	from[tedges] = b;
	to[tedges] = a;
	cap[tedges] = 0;
	flow[tedges] = 0;
	next[tedges] = last[b];
	last[b] = tedges++;
}

bool bfs() {
	for (int i = 0; i < tnodes; i++) {
		depth[i] = -1;
	}
	depth[source] = 0;
	qh = qt = 0;
	Q[qt++] = source;
	while (qh != qt) {
		int u = Q[qh++];
		for (int e = last[u]; e != -1; e = next[e]) {
			if (cap[e] > flow[e]) {
				int v = to[e];
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
	if (u == sink) {
		return f;
	}
	for (int e = now[u]; e != -1; e = now[u] = next[e]) {
		if (cap[e] > flow[e]) {
			int v = to[e];
			if (depth[v] == depth[u] + 1) {
				int ff = min(f, cap[e] - flow[e]);
				int push = dfs(v, ff);
				if (push > 0) {
					flow[e] += push;
					flow[e ^ 1] -= push;
					return push;
				}
			}
		}
	}
	return 0;
}

int maxFlow() {
	int res = 0;
	while (bfs()) {
		for (int i = 0; i < tnodes; i++) {
			now[i] = last[i];
		}
		while (true) {
			int tmp = dfs(source, INF);
			if (tmp == 0) {
				break;
			}
			res += tmp;
		}
	}
	return res;
}

int t;
int n;
int a[MAXV];
string s[MAXV];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int total = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			total += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		tnodes = 2 * n + 2;
		source = 2 * n;
		sink = 2 * n + 1;
		int lo = 1;
		int hi = total;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			tedges = 0;
			for (int i = 0; i < tnodes; i++) {
				last[i] = -1;
			}
			for (int i = 0; i < n; i++) {
				addEdge(source, i, a[i]);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (s[i][j] == 'Y') {
						addEdge(i, n + j, a[i]);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				addEdge(i, n + i, a[i]);
			}
			int need = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == 0) {
					continue;
				}
				bool borde = false;
				for (int j = 0; j < n; j++) {
					if (s[i][j] == 'Y' && a[j] == 0) {
						borde = true;
						break;
					}
				}
				if (borde) {
					addEdge(n + i, sink, mid);
					need += mid;
				} else {
					addEdge(n + i, sink, 1);
					need++;
				}
			}
			if (maxFlow() == need) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}
