#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAXN = 1005, MAXM = 200100;

int n, m, k;
int ady[MAXM], cap[MAXM], flow[MAXM], next[MAXM], last[MAXN], E, now[MAXN];
int s, t, lev[MAXN];
int Q[MAXN + 5], qh, qt;

bool bfs() {
  for (int i = 0; i <= n; i++)
    lev[i] = 0;
	lev[0] = 1;
	qh = qt = 0;
	Q[qt++] = 0;
	int u;
	while (qt > qh) {
		u = Q[qh++];
		for (int e = last[u]; e != -1; e = next[e])
			if (cap[e] > flow[e] && !lev[ady[e]]) {
				lev[ady[e]] = lev[u] + 1;
				Q[qt++] = ady[e];
			}
	}
	return lev[n];
}

int dfs(int u, int cur) {
	if (u == n) return cur;
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
		for (int i = 0; i <= n; i++)
			now[i] = last[i];
		while ((f = dfs(0, 1 << 29)) > 0) tot += f;
	}
	return tot;
}

int main() {
  //freopen("e.in", "r", stdin);
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		E = 0;
		for (int i = 0; i <= n; i++)
			last[i] = -1;
		for (int i = 0, x; i < k; i++) {
			scanf("%d", &x);
			ady[E] = x; cap[E] = 1 << 29; flow[E] = 0; next[E] = last[0]; last[0] = E++;
			ady[E] = 0; cap[E] = 0; flow[E] = 0; next[x] = last[x]; last[x] = E++;
		}
		for (int i = 0, a, b; i < m; i++) {
			scanf("%d%d", &a, &b);
			ady[E] = b; cap[E] = 1; flow[E] = 0; next[E] = last[a]; last[a] = E++;
      			ady[E] = a; cap[E] = 1; flow[E] = 0; next[E] = last[b]; last[b] = E++;
		}
		printf("%d\n", maxFlow());
	}
}
