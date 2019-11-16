#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
int val[N];
vector <int> g[N];
int parent[N];
int depth[N];
int q, x, y, z;

void dfs(int u, int p, int d) {
	parent[u] = p;
	depth[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != p) {
			dfs(v, u, d + 1);
		}
	}
}

int solve(int u, int v) {
	int res = val[v];
	if (depth[v] > depth[u]) {
		swap(u, v);
	}
	while (depth[u] > depth[v]) {
		res = __gcd(res, val[u]);
		u = parent[u];
	}
	while (u != v) {
		res = __gcd(res, __gcd(val[u], val[v]));
		u = parent[u];
		v = parent[v];
	}
	res = __gcd(res, val[u]);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("dat.txt", "r", stdin);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> val[i];
			g[i].clear();
			depth[i] = -1;
		}
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(0, -1, 0);
		for (int i = 0; i < n; i++) {
            assert(depth[i] != -1);
		}
		cin >> q;
		while (q--) {
			cin >> x >> y >> z;
			if (x == 1) {
				cout << solve(y, z) << "\n";
			} else {
				val[y] = z;
			}
		}
	}
}
