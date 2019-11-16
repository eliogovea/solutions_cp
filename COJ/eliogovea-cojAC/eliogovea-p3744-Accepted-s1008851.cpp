#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int INF = 1e9;

int n;
int a[N];
int b[N];
vector <int> tree[N];
int subTreeSize[N];
bool processed[N];
int dParent[N];
int dDepth[N];
int dNodes[N], dTimer;
int dTimeIn[N], dTimeOut[N];
int values[20][N];

int calcSubTreeSize(int u, int p) {
	subTreeSize[u] = 1;
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p || processed[v]) {
			continue;
		}
		subTreeSize[u] += calcSubTreeSize(v, u);
	}
	return subTreeSize[u];
}

int findSplitNode(int u, int p, int total) {
	int maxSubTree = total - subTreeSize[u];
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p || processed[v]) {
			continue;
		}
		maxSubTree = max(maxSubTree, subTreeSize[v]);
	}
	if (maxSubTree <= total / 2) {
		return u;
	}
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p || processed[v]) {
			continue;
		}
		int x = findSplitNode(v, u, total);
		if (x != -1) {
			return x;
		}
	}
	return -1;
}

int decomposeTree(int u) {
	int total = calcSubTreeSize(u, -1);
	int centroid = findSplitNode(u, -1, total);
	dTimeIn[centroid] = dTimer;
	dNodes[dTimer++] = centroid;
	processed[centroid] = true;
	for (int i = 0; i < tree[centroid].size(); i++) {
		int v = tree[centroid][i];
		if (!processed[v]) {
			int x = decomposeTree(v);
			dParent[x] = centroid;
		}
	}
	dTimeOut[centroid] = dTimer - 1;
	return centroid;
}

struct data {
	int value;
	int node;
	data() {
		value = -INF;
		node = -1;
	}
	data(int _value, int _node) : value(_value), node(_node) {}
};

data operator + (const data &a, const data &b) {
	if (a.value > b.value) {
		return a;
	}
	if (b.value > a.value) {
		return b;
	}
	if (a.node < b.node) {
		return a;
	}
	return b;
}

struct SegmentTree {
	int n;
	vector <data> tree;
	SegmentTree() {}
	SegmentTree(int _n) {
		n = _n;
		tree = vector <data>(4 * n);
	}
	void build(int *values, int *nodes, int x, int l, int r) {
		if (l == r) {
			tree[x].value = values[l - 1];
			tree[x].node = nodes[l - 1] + 1;
		} else {
			int mid = (l + r) >> 1;
			build(values, nodes, 2 * x, l, mid);
			build(values, nodes, 2 * x + 1, mid + 1, r);
			tree[x] = tree[2 * x] + tree[2 * x + 1];
		}
	}
	void update(int x, int l, int r, int p, int v) {
		if (p < l || r < p) {
			return;
		}
		if (l == r) {
			tree[x].value = v;
		} else {
			int mid = (l + r) >> 1;
			update(2 * x, l, mid, p, v);
			update(2 * x + 1, mid + 1, r, p, v);
			tree[x] = tree[2 * x] + tree[2 * x + 1];
		}
	}
	void update(int p, int v) {
		update(1, 1, n, p, v);
	}
	data query(int x, int l, int r, int ql, int qr) {
		if (r < ql || qr < l) {
			return data();
		}
		if (ql <= l && r <= qr) {
			return tree[x];
		}
		int mid = (l + r) >> 1;
		data q1 = query(2 * x, l, mid, ql, qr);
		data q2 = query(2 * x + 1, mid + 1, r, ql, qr);
		return q1 + q2;
	}
	data query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

map <pair <int, int>, int> dist;

void dfs(int root, int now, int from, int depth) {
	values[dDepth[root]][dTimeIn[now]] = b[now] - depth;
	dist[make_pair(root, now)] = depth;
	for (int i = 0; i < tree[now].size(); i++) {
		int to = tree[now][i];
		if (dDepth[to] <= dDepth[root] || to == from) {
			continue;
		}
		dfs(root, to, now, depth + 1);
	}
}

void solve() {
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		tree[i].clear();
		processed[i] = false;
		dParent[i] = -1;
		dDepth[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	dTimer = 0;
	int dRoot = decomposeTree(0);

	for (int i = 1; i < n; i++) {
        dDepth[dNodes[i]] = dDepth[dParent[dNodes[i]]] + 1;
	}

	int maxDepth = 0;
	for (int i = 0; i < n; i++) {
		maxDepth = max(maxDepth, dDepth[i]);
	}
	vector <SegmentTree> st(maxDepth + 1, SegmentTree(n));
	for (int l = 0; l <= maxDepth; l++) {
		for (int i = 0; i < n; i++) {
			values[l][i] = -INF;
		}
	}
	for (int i = 0; i < n; i++) {
		dfs(i, i, -1, 0);
	}
	for (int i = 0; i <= maxDepth; i++) {
		st[i].build(values[i], dNodes, 1, 1, n);
	}
	int queries;
	cin >> queries;
	while (queries--) {
		int type;
		cin >> type;
		if (type == 0) {
			int u, x;
			cin >> u >> x;
			u--;
			a[u] = x;
		} else if (type == 1) {
			int u, x;
			cin >> u >> x;
			u--;
			int now = u;
			while (now != -1) {
				st[dDepth[now]].update(1, 1, n, dTimeIn[u] + 1, x - dist[make_pair(now, u)]);
				now = dParent[now];
			}
		} else {
			int u;
			cin >> u;
			u--;
			data ans = st[dDepth[u]].query(1, 1, n, dTimeIn[u] + 1, dTimeOut[u] + 1);
			int now = dParent[u];
			while (now != -1) {
				data tmp = st[dDepth[now]].query(1, 1, n, dTimeIn[now] + 1, dTimeOut[now] + 1);
                assert(dist.find(make_pair(now, u)) != dist.end());
				tmp.value -= dist[make_pair(now, u)];
				ans = ans + tmp;
				now = dParent[now];
			}
			assert(1 <= ans.node && ans.node <= n);
			cout << ans.node << " " << ans.value + a[u] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

}
