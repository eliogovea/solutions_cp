#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int n, q, x, y, z;
vector <int> g[N];
int val[N];
int parent[N], depth[N], size[N], chain[N], heavy[N], head[N];

struct ST {
	int n;
	vector <int> chain;
	vector <int> tree;
	ST() {}
	ST(vector <int> &_chain) {
		chain = _chain;
		n = chain.size();
		tree = vector <int>(4 * n, 0);
		build(1, 1, n);
	}
	void build(int x, int l, int r) {
		if (l == r) {
			tree[x] = chain[l - 1];
		} else {
			int mid = (l + r) >> 1;
			build(2 * x, l, mid);
			build(2 * x + 1, mid + 1, r);
			tree[x] = __gcd(tree[2 * x], tree[2 * x + 1]);
		}
	}
	void update(int x, int l, int r, int p, int v) {
		if (p > r || p < l) {
			return;
		}
		if (l == r) {
			tree[x] = v;
		} else {
			int mid = (l + r) >> 1;
			update(2 * x, l, mid, p, v);
			update(2 * x + 1, mid + 1, r, p, v);
			tree[x] = __gcd(tree[2 * x], tree[2 * x + 1]);
		}
	}
	void update(int p, int v) {
		update(1, 1, n, p, v);
	}
	int query(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) {
			return 0;
		}
		if (l >= ql && r <= qr) {
			return tree[x];
		}
		int mid = (l + r) >> 1;
		int q1 = query(2 * x, l, mid, ql, qr);
		int q2 = query(2 * x + 1, mid + 1, r, ql, qr);
		return __gcd(q1, q2);
	}
	int query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

vector <ST> chains;

void dfs(int u, int p, int d) {
	parent[u] = p;
	depth[u] = d;
	heavy[u] = -1;
	size[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != p) {
			dfs(v, u, d + 1);
			size[u] += size[v];
			if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
				heavy[u] = v;
			}
		}
	}
}

void hld() {
	for (int i = 0; i < n; i++) {
		depth[i] = -1;
		parent[i] = -1;
	}
	dfs(0, -1, 0);
	chains.clear();
	for (int i = 0; i < n; i++) {
		if (i == 0 || heavy[parent[i]] != i) {
			vector <int> v;
			for (int j = i; j != -1; j = heavy[j]) {
				v.push_back(val[j]);
				chain[j] = chains.size();
				head[j] = i;
				//cout << j << " ";
			}
			//cout << "\n";
			chains.push_back(ST(v));
		}
	}
}

void update(int u, int x) {
	chains[chain[u]].update(depth[u] - depth[head[u]] + 1, x);
}

int query(int u, int v) {
	int res = 0;
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) {
			res = __gcd(res, chains[chain[u]].query(1, depth[u] - depth[head[u]] + 1));
			u = parent[head[u]];
		} else {
			res = __gcd(res, chains[chain[v]].query(1, depth[v] - depth[head[v]] + 1));
			v = parent[head[v]];
		}
	}
	if (depth[u] > depth[v]) {
		res = __gcd(res, chains[chain[u]].query(depth[v] - depth[head[v]] + 1, depth[u] - depth[head[u]] + 1));
	} else {
		res = __gcd(res, chains[chain[v]].query(depth[u] - depth[head[u]] + 1, depth[v] - depth[head[v]] + 1));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n) {
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
		for (int i = 0; i < n; i++) {
			cin >> val[i];
		}
		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		hld();


		cin >> q;
		while (q--) {
			cin >> x >> y >> z;
			if (x == 1) {
				cout << query(y, z) << "\n";
			} else {
				update(y, z);
			}
		}
	}
}
