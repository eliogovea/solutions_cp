#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

const ll inf = 1ll << 60;

int n, q, cnt;
vector<int> G[MAXN];
int depth[MAXN], chain[MAXN], head[MAXN];
int parent[MAXN], heavy[MAXN], size[MAXN];

struct ST {
	int size;
	vector<ll> T;
	ST(int sz) {
        size = sz;
        int tmp = 2 + log2(sz);
		tmp = 1 << tmp;
		T.resize(tmp, 0);
	}
	void update(int idx, int l, int r, int p, int v) {
		if (p < l || p > r) return;
		if (l == r && l == p) T[idx] += v;
		else {
			int mid = (l + r) / 2;
			update(2 * idx, l, mid, p, v);
			update(2 * idx + 1, mid + 1, r, p, v);
			T[idx] = max(T[2 * idx], T[2 * idx + 1]);
		}
	}
	void update(int node, int value) {
		update(1, 1, size, 1 + depth[node] - depth[head[node]], value);
	}
	ll query(int idx, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) return -inf;
		if (l >= ql && r <= qr) return T[idx];
		int mid = (l + r) / 2;
		return max(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
	}
	ll query(int a, int b) {
		a = 1 + depth[a] - depth[head[a]];
		b = 1 + depth[b] - depth[head[b]];
		if (a > b) swap(a, b);
		return query(1, 1, size, a, b);
	}
};

vector<ST> chains;

void dfs(int u) {
	size[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == parent[u]) continue;
		parent[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
		if (heavy[u] == -1 || size[v] > size[heavy[u]])
            heavy[u] = v;
	}
}

void heavy_light() {
	for (int i = 0; i <= n; i++) heavy[i] = -1;
	parent[0] = -1;
	depth[0] = 0;
	dfs(0);
	for (int i = 0; i <= n; i++)
		if (parent[i] == -1 || heavy[parent[i]] != i) {
			int tmp = 0;
			for (int j = i; j != -1; j = heavy[j]) {
				chain[j] = cnt;
				head[j] = i;
				tmp++;
			}
			cnt++;
			chains.push_back(ST(tmp));
		}
}

void update(int node, int value) {
	chains[chain[node]].update(node, value);
}

ll query(int u, int v) {
	ll ret = -inf;
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) {
			ret = max(ret, chains[chain[u]].query(head[u], u));
			u = parent[head[u]];
		}
		else {
			ret = max(ret, chains[chain[v]].query(head[v], v));
			v = parent[head[v]];
		}
	}
	ret = max(ret, chains[chain[u]].query(u, v));
	return ret;
}


int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d", &n);
	G[0].push_back(1);
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	heavy_light();
	char op[2];
	ll a, b;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%lld%lld", op, &a, &b);
		if (op[0] == 'I') update(a, b);
		else printf("%lld\n", query(a, b));
	}
}
