#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 10005;
 
int tc, n;
vector<int> g[N], c[N];
 
int size[N], heavy[N], par[N], chain[N], head[N], depth[N], dist[N];
 
void dfs(int u, int p, int d, int di) {
	size[u] = 1;
	heavy[u] = -1;
	par[u] = p;
	depth[u] = d;
	dist[u] = di;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		dfs(v, u, d + 1, di + c[u][i]);
		size[u] += size[v];
		if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
			heavy[u] = v;
		}
	}
}
 
int cnt;
vector<int> ch[N];
 
void HLD() {
	for (int i = 0; i < cnt; i++) {
		ch[i].clear();
	}
	cnt = 0;
	dfs(1, 0, 0, 0);
	for (int i = 1; i <= n; i++) {
		if (i == 1 || heavy[par[i]] != i) {
			for (int j = i; j != -1; j = heavy[j]) {
				head[j] = i;
				chain[j] = cnt;
				ch[cnt].push_back(j);
			}
			cnt++;
		}
	}
}
 
int lca(int u, int v) {
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) {
			u = par[head[u]];
		} else {
			v = par[head[v]];
		}
	}
	if (depth[u] < depth[v]) {
		return u;
	}
	return v;
}
 
int find_kth(int u, int v, int k) {
	//cout << "Query " << u << " " << v << " " << k << "\n";
	int l = lca(u, v);
	//cout << "lca: " << l << "\n";
	int s = depth[u] - depth[l] + depth[v] - depth[l] + 1;
	int x = depth[u] - depth[l] + 1;
	if (k <= x) {
		//cout << "Caso 1\n";
		while (depth[u] - depth[head[u]] + 1 < k) {
			k -= depth[u] - depth[head[u]] + 1;
			u = par[head[u]];
		}
		int pos = depth[u] - depth[head[u]] - k + 1;
		return ch[chain[u]][pos];
	} else {
		//cout << "Caso 2\n";
		u = v;
		k = s - k + 1;
		//cout << u << " " << k << "\n";
		while (depth[u] - depth[head[u]] + 1 < k) {
			k -= depth[u] - depth[head[u]] + 1;
			u = par[head[u]];
		}
		int pos = depth[u] - depth[head[u]] - k + 1;
		//cout << u << " " << pos << "\n";
		return ch[chain[u]][pos];
	}
}
 
int get_dist(int u, int v) {
	int l = lca(u, v);
	return dist[u] + dist[v] - 2 * dist[l];
}
 
int x, y, z;
string s;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("data.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			c[i].clear();
		}
		for (int i = 1; i < n; i++) {
			cin >> x >> y >> z;
			g[x].push_back(y);
			c[x].push_back(z);
			g[y].push_back(x);
			c[y].push_back(z);
		}
		HLD();
		while (cin >> s) {
			if (s[1] == 'O') {
				break;
			}
			if (s[1] == 'I') {
				cin >> x >> y;
				cout << get_dist(x, y) << "\n";
			} else {
				cin >> x >> y >> z;
				cout << find_kth(x, y, z) << "\n";
			}
		}
		cout << "\n";
	}
}
