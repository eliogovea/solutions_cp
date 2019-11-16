#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAXN = 100005;

int N, M, cnt;
vector<int> ady[MAXN];
int depth[MAXN], heavy[MAXN], parent[MAXN];
int size[MAXN], chain[MAXN], head[MAXN];


struct ST {
	int size;
	vector<int> T, lazy;
	ST() {}
	ST(int sz) {
	  size = sz;
		int tmp = 2 + log2(sz);
		tmp = 1 << tmp;
		T.resize(tmp, 0);
		lazy.resize(tmp, 0);
	}
	void propagate(int idx, int l, int r) {
		if (lazy[idx]) {
			T[idx] += (r - l + 1) * lazy[idx];
			if (l != r) {
				lazy[2 * idx] += lazy[idx];
				lazy[2 * idx + 1] += lazy[idx];
			}
			lazy[idx] = 0;
		}
	}
	void update(int idx, int l, int r, int ul, int ur, int upd) {
		propagate(idx, l, r);
		if (l > ur || r < ul) return;
		if (l >= ul && r <= ur) {
			T[idx] += (r - l + 1) * upd;
			if (l != r) {
				lazy[2 * idx] += upd;
				lazy[2 * idx + 1] += upd;
			}
		}
		else {
			int m = (l + r) / 2;
			update(2 * idx, l, m, ul, ur, upd);
			update(2 * idx + 1, m + 1, r, ul, ur, upd);
			T[idx] = T[2 * idx] + T[2 * idx + 1];
		}
	}
	void update(int node, int value) {
		int d = 1 + depth[node] - depth[head[node]];
		update(1, 1, size, 1, d, value);
	}
	int query(int idx, int l, int r, int ql, int qr) {
		propagate(idx, l, r);
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return T[idx];
		int m = (l + r) / 2;
		return query(2 * idx, l, m, ql, qr) + query(2 * idx + 1, m + 1, r, ql, qr);
	}
	int query(int node) {
		int d = 1 + depth[node] - depth[head[node]];
		return query(1, 1, size, 1, d);
	}
};

vector<ST> chains;

void dfs(int u) {
	size[u] = 1;
	for (int i = 0; i < ady[u].size(); i++) {
		int v = ady[u][i];
		if (v == parent[u]) continue;
		parent[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
		size[u] += size[v];
		if (heavy[u] == -1 || size[v] > size[heavy[u]])
			heavy[u] = v;
	}
}

void heavy_light() {
  for (int i = 0; i < N; i++) heavy[i] = -1;
	parent[0] = -1;
	depth[0] = 0;
	dfs(0);
	cnt = 0;
	for (int i = 0; i < N; i++)
		if (parent[i] == -1 || heavy[parent[i]] != i) {
			int tmp = 0;
			for (int j = i; j != -1; j = heavy[j]) {
				head[j] = i;
				chain[j] = cnt;
				tmp++;
			}
			chains.push_back(ST(tmp));
			cnt++;
		}
}

inline int lca(int u, int v) {
	while (chain[u] != chain[v]) {
		if (depth[head[u]] > depth[head[v]]) swap(u, v);
			v = parent[head[v]];
	}
	if (depth[u] < depth[v]) return u;
	return v;
}

inline void update(int node, int value) {
	for (; node != -1; node = parent[head[node]])
		chains[chain[node]].update(node, value);
}

inline int query(int node) {
	int ret = 0;
	for (; node != -1; node = parent[head[node]])
		ret += chains[chain[node]].query(node);
	return ret;
}

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i < N; i++) {
		scanf("%d%d", &x, &y);
		x--; y--;
		ady[x].push_back(y);
		ady[y].push_back(x);
	}
	heavy_light();
	char c[2];
	int a, b;
	while (M--) {
		scanf("%s%d%d", c, &a, &b);
		a--; b--;
		int v = lca(a, b);
		if (c[0] == 'P') {
			update(a, 1);
			update(b, 1);
			update(v, -2);
		}
		else {
      int r = query(a) + query(b) - 2 * query(v);
      printf("%d\n", r);
		}
	}
}
