#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 40, MAXN = 2500, MAXE = 10000;

int n, m, mat[MAXLEN][MAXLEN], ind = 1, source, sink;
int ady[MAXE], cap[MAXE], flow[MAXE], next[MAXE], last[MAXE], E;
int id, used[MAXN];
char line[MAXLEN];

inline void addEdge(int a, int b) {
	ady[E] = b; cap[E] = 1; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

int dfs(int u, int currFlow) {
	if (u == sink) return currFlow;
	if (used[u] == id) return 0;
	used[u] = id;
	for (int e = last[u]; e != -1; e = next[e])
		if (cap[e] > flow[e]) {
			int res = dfs(ady[e], min(currFlow, cap[e] - flow[e]));
			if (res > 0) {
				flow[e] += res;
				flow[e ^ 1] -= res;
				return res;
			}
		}
	return 0;
}

int maxFlow() {
	int f, flow = 0;
	while (true) {
		id++;
		f = dfs(source, 1 << 29);
		if (f == 0) return flow;
		flow += f;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", line);
		if (m == 0) {
			m = strlen(line);
			source = 0;
			sink = 2 * n * m + 1;
			for (int i = 0; i <= sink; i++) last[i] = -1;
		}
		for (int j = 0; j < m; j++) {
			mat[i][j] = ind++;
			addEdge(mat[i][j], n * m + mat[i][j]);
			if (line[j] == '1') addEdge(source, mat[i][j]);
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
				addEdge(n * m + mat[i][j], sink);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i > 0) addEdge(n * m + mat[i][j], mat[i - 1][j]);
			if (j > 0) addEdge(n * m + mat[i][j], mat[i][j - 1]);
			if (i < n - 1) addEdge(n * m + mat[i][j], mat[i + 1][j]);
			if (j < m - 1) addEdge(n * m + mat[i][j], mat[i][j + 1]);
		}
	printf("%d\n", maxFlow());
}
