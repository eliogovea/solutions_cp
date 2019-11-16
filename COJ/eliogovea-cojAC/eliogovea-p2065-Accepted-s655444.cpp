/// COJ - 2065 - Invasion

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 5005, MAXM = 70005, inf = 1 << 29;

int n, m;
int ady[MAXM], cap[MAXM], flow[MAXM], next[MAXM], last[MAXN], now[MAXN], E;
int lev[MAXN], Q[MAXM], qh, qt;
int source, sink;

inline void addEdge(int a, int b, int c) {
	ady[E] = b; cap[E] = c; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = c; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

bool bfs() {
	for (int i = 1; i <= n; i++)
		lev[i] = 0;
	lev[source] = 1;
	qh = qt = 0;
	Q[qh++] = source;
	while (qh > qt) {
		int u = Q[qt++];
		for (int e = last[u]; e != -1; e = next[e])
			if (cap[e] > flow[e] && !lev[ady[e]]) {
				lev[ady[e]] = lev[u] + 1;
				if (ady[e] == sink) return true;
				Q[qh++] = ady[e];
			}
	}
	return false;
}

int dfs(int u, int cur) {
	if (u == sink) return cur;
	for (int e = now[u]; e != -1; e = now[u] = next[e])
		if (cap[e] > flow[e] && lev[ady[e]] == lev[u] + 1) {
			int r = dfs(ady[e], min(cur, cap[e] - flow[e]));
			if (r > 0) {
				flow[e] += r;
				flow[e ^ 1] -= r;
				return r;
			}
		}
	return 0;
}

int maxFlow() {
	int f, tot = 0;
	while (bfs()) {
		for (int i = 1; i <= n; i++)
			now[i] = last[i];
		while (f = dfs(source, inf)) tot += f;
	}
	return tot;
}

int a, b, x;

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) last[i] = -1;

	source = 1;
	sink = n;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		addEdge(a, b, c);
	}

	cout << maxFlow() << " ";
	for (int i = 0; i < E; i++) {
		if (cap[i] == flow[i]) cap[i] = 1;
		else cap[i] = inf;
		flow[i] = 0;
	}
	cout << maxFlow() << "\n";
}
