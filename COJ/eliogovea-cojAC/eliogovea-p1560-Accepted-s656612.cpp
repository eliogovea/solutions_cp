#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2005, MAXM = 2000100;

int tc, n, m;
int ady[MAXM], cap[MAXM], flow[MAXM], next[MAXM], last[MAXN], E, now[MAXN];
int s, t, lev[MAXN];
int Q[MAXN + 5], qh, qt;
bool mark[MAXN][MAXN];

inline void addEdge(int a, int b, int c) {
	ady[E] = b; cap[E] = c; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

bool bfs() {
  for (int i = 1; i <= 2 * n; i++) lev[i] = 0;
	lev[s] = 1;
	qh = qt = 0;
	Q[qt++] = s;
	int u;
	while (qt > qh) {
		u = Q[qh++];
		for (int e = last[u]; e != -1; e = next[e])
			if (cap[e] > flow[e] && !lev[ady[e]]) {
				lev[ady[e]] = lev[u] + 1;
				Q[qt++] = ady[e];
			}
	}
	return lev[t];
}

int dfs(int u, int cur) {
	if (u == t) return cur;
	for (int e = now[u], r; e != -1; e = now[u] = next[e])
		if (cap[e] > flow[e] && lev[ady[e]] == lev[u] + 1) {
			r = dfs(ady[e], min(cur, cap[e] - flow[e]));
			if (r > 0) {
				flow[e] += r;
				flow[e ^ 1] -= r;
				return r;
			}
		}
	return 0;
}

int maxFlow() {
	int tot = 0, f;
	while (bfs()) {
		for (int i = 1; i <= 2 * n; i++) now[i] = last[i];
		while ((f = dfs(s, 1 << 29)) > 0) tot += f;
	}
	return tot;
}

int main() {
  //freopen("e.in", "r", stdin);
  scanf("%d", &tc);
	while (tc--) {
    scanf("%d%d%d%d", &n, &m, &s, &t);
		E = 0;
		t += n;
		for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        mark[i][j] = mark[j][i] = false;
		for (int i = 1; i <= 2 * n; i++) last[i] = -1;
		for (int i = 1; i <= n; i++) addEdge(i, n + i, (i == s || n + i == t) ? 1 << 29 : 1);
		for (int i = 1, a, b; i <= m; i++) {
			scanf("%d%d", &a, &b);
			if (!mark[a][b]) {
        addEdge(n + a, b, 1);
        addEdge(n + b, a, 1);
			}
			mark[a][b] = mark[b][a] = true;
		}
		printf("%d\n", maxFlow());
	}
}
