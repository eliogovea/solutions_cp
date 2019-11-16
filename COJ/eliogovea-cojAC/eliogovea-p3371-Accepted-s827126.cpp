#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
vector<int> g[N];

int size[N], depth[N], par[N], head[N], chain[N], heavy[N];

void dfs(int u, int p, int d) {
	par[u] = p;
	depth[u] = d;
	size[u] = 1;
	heavy[u] = -1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		dfs(v, u, d + 1);
		size[u] += size[v];
		if (heavy[u] == -1 || size[v] > size[heavy[u]]) {
			heavy[u] = v;
		}
	}
}
// (a, b) -> (b, a % b)
inline int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

struct ST {
	int sz;
	vector<int> t;
	ST(int n) {
		sz = n;
		t.clear();
		t.resize(4 * (n + 5));
	}
	void update(int x, int l, int r, int p, int v) {
		if (p < l || p > r) {
			return;
		}
		if (l == r) {
			t[x] = v;
		} else {
			int m = (l + r) >> 1;
			update(2 * x, l, m, p, v);
			update(2 * x + 1, m + 1, r, p, v);
			t[x] = gcd(t[2 * x], t[2 * x + 1]);
		}
	}
	void update(int p, int v) {
		update(1, 1, sz, p, v);
	}
	int query(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) {
			return 0;
		}
		if (l >=ql && r <= qr) {
			return t[x];
		}
		int m = (l + r) >> 1;
		int q1 = query(2 * x, l, m, ql, qr);
		int q2 = query(2 * x + 1, m + 1, r, ql, qr);
		return gcd(q1, q2);
	}
	int query(int ql, int qr) {
		return query(1, 1, sz, ql, qr);
	}
};

vector<ST> chains;

void HLD() {
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		if (i == 1 || heavy[par[i]] != i) {
			int cnt = 0;
			for (int j = i; j != -1; j = heavy[j]) {
				chain[j] = chains.size();
				head[j] = i;
				cnt++;
			}
			chains.push_back(ST(cnt));
		}
	}
}

void update(int u, int val) {
	chains[chain[u]].update(depth[u] - depth[head[u]] + 1, val);
}

int query(int u, int v) {
	int ans = 0;
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) {
			ans = gcd(ans, chains[chain[u]].query(1, depth[u] - depth[head[u]] + 1));
			u = par[head[u]];
		} else {
			ans = gcd(ans, chains[chain[v]].query(1, depth[v] - depth[head[v]] + 1));
			v = par[head[v]];
		}
	}
	int lo = depth[u] - depth[head[u]] + 1;
	int hi = depth[v] - depth[head[v]] + 1;
	if (lo > hi) {
		swap(lo, hi);
	}
	ans = gcd(ans, chains[chain[u]].query(lo, hi));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	HLD();
	while (m--) {
		char ty;
		int u, v;
		cin >> ty >> u >> v;
		if (ty == 'U') {
			update(u, v);
		} else {
			cout << query(u, v) << "\n";
		}
	}
}
