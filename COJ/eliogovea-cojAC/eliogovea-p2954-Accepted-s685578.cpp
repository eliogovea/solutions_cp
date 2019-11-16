#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

typedef long long LL;

int n, s;
LL x[MAXN], y[MAXN];
vector<int> ady[MAXN];
vector<LL> dist[MAXN];
int C, T;
LL D;

LL dm(int a, int b) {
	LL dx = x[a] - x[b]; if (dx < 0) dx = -dx;
	LL dy = y[a] - y[b]; if (dy < 0) dy = -dy;
	return dx + dy;
}

int parent[MAXN], size[MAXN], heavy[MAXN], chain[MAXN], head[MAXN], depth[MAXN];
LL Dist[MAXN];

void dfs(int u, int p, LL d) {
	Dist[u] = d;
	parent[u] = p;
	depth[u] = depth[p] + 1;
	size[u] = 1;
	for (int i = 0; i < (int)ady[u].size(); i++) {
		int v = ady[u][i];
		LL ds = dist[u][i];
		if (v == p) continue;
		dfs(v, u, d + ds);
		size[u] += size[v];
		if (heavy[u] == -1 || size[heavy[u]] < size[v])
			heavy[u] = v;
	}
}

void HL() {
	for (int i = 1; i <= n; i++) heavy[i] = -1;
	dfs(1, 0, 0);
	int ch = 0;
	for (int i = 1; i <= n; i++)
		if (parent[i] == 0 || heavy[parent[i]] != i) {
			for (int j = i; j != -1; j = heavy[j]) {
				chain[j] = ch;
				head[j] = i;
			}
			ch++;
		}
}

int lca(int u, int v) {
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) u = parent[head[u]];
		else v = parent[head[v]];
	}
	if (depth[u] < depth[v]) return u;
	return v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		ady[a].push_back(b);
		dist[a].push_back(dm(a, b));
		ady[b].push_back(a);
		dist[b].push_back(dm(a, b));
	}
	HL();
	for (int i = 1, a, b; i <= s; i++) {
		cin >> a >> b;
		int l = lca(a, b);
		int cnt = depth[a] + depth[b] - 2 * depth[l] + 1;
		LL dis = Dist[a] + Dist[b] - 2 * Dist[l] + dm(a, b);
		if (cnt > C || (cnt == C && dis < D)) {
			T = 1;
			C = cnt;
			D = dis;
		}
		else if (cnt == C && dis == D) T++;
	}
	cout << "Markets: " << C << "\nRoute Lenght: " << D
		<< "\nNumber of optimal suggestions: " << T << "\n";
}
