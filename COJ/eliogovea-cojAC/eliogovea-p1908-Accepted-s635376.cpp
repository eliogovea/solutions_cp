/// COJ - 1908 - Rainbow Party

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 1005, MAXM = 400005, inf = 1 << 29;

int n, s, p;
int ady[MAXM], cap[MAXM], flow[MAXM], next[MAXM], last[MAXN], now[MAXN], E;
int lev[MAXN], Q[MAXM], qh, qt;
int source, sink;

inline void addEdge(int a, int b) {
	ady[E] = b; cap[E] = 1; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

bool bfs() {
	for (int i = 0; i <= s + p + 1 + n + n; i++)
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
		for (int i = 0; i <= s + p + n + n + 1; i++)
			now[i] = last[i];
		while (f = dfs(source, inf)) tot += f;
	}
	return tot;
}

int a, b, x;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n >> s >> p;
  E = 0;
	for (int i = 0; i <= s + p + 1 + n + n; i++)
      last[i] = -1;

	source = 0;
	sink = 1;

	for (int i = 1; i <= s; i++)
		addEdge(source, i + 1);
	for (int i = 1; i <= p; i++)
		addEdge(i + s + 1, sink);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		while (a--) {
			cin >> x;
			addEdge(x + 1, 1 + s + p + i);
		}
		addEdge(1 + s + p + i, 1 + s + p + n + i);
		while (b--) {
			cin >> x;
			addEdge(1 + s + p + n + i, s + 1 + x);
		}
	}
	cout << maxFlow() << '\n';
}
