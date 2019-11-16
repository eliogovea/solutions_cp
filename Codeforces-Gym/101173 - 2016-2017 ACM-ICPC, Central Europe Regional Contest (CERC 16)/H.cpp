// 2016-2017 ACM-ICPC, Central Europe Regional Contest (CERC 16)
// 101173H

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n;
string mat[N];
int sum[N][N];
int val[N][N];

inline int getSum(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

inline bool inside(int x, int n) { // [0, n)
	return (0 <= x && x < n);
}

inline int getID(int x, int y, int n) {
	return x * n + y;
}

vector <pair <int, int> > G[N * N];

struct edge {
	int from;
	int to;
	int val;
};

bool operator < (const edge &a, const edge &b) {
	return a.val > b.val;
}

vector <edge> E;

int parent[N * N];

int find(int x) {
	if (x != parent[x]) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	if (rand() & 1) {
		parent[x] = y;
	} else {
		parent[y] = x;
	}
	return true;
}

const int LOG = 20;

bool visited[N * N];
int par[LOG + 2][N * N];
int minEdge[LOG + 2][N * N];
int timer = 0;
int tin[N * N];
int tout[N * N];
int componentCount;
int component[N * N];

void dfs(int u, int p, int e) {
	tin[u] = timer++;
	component[u] = componentCount;
	par[0][u] = p;
	minEdge[0][u] = e;
	for (int i = 1; i < LOG; i++) {
		if (par[i - 1][u] != -1) {
			par[i][u] = par[i - 1][par[i - 1][u]];
			minEdge[i][u] = min(minEdge[i - 1][u], minEdge[i - 1][par[i - 1][u]]);
		}
	}
	visited[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		if (!visited[v]) {
			dfs(v, u, G[u][i].second);
		}
	}
	tout[u] = timer++;
}

inline bool isAncestor(int u, int v) {
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

inline int getMinEdge(int u, int v) {
	int res = -1;
	if (!isAncestor(u, v)) {
		int uu = u;
		for (int i = LOG - 1; i >= 0; i--) {
			if (par[i][uu] == -1) {
				continue;
			}
			if (!isAncestor(par[i][uu], v)) {
				if (res == -1 || minEdge[i][uu] < res) {
					res = minEdge[i][uu];
				}
				uu = par[i][uu];
			}
		}
		if (res == -1 || minEdge[0][uu] < res) {
			res = minEdge[0][uu];
		}
	}
	if (!isAncestor(v, u)) {
		int vv = v;
		for (int i = LOG - 1; i >= 0; i--) {
			if (par[i][vv] == -1) {
				continue;
			}
			if (!isAncestor(par[i][vv], u)) {
				if (res == -1 || minEdge[i][vv] < res) {
					res = minEdge[i][vv];
				}
				vv = par[i][vv];
			}
		}
		if (res == -1 || minEdge[0][vv] < res) {
			res = minEdge[0][vv];
		}
	}
	assert(res != -1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = (mat[i - 1][j - 1] == '#') ? 1 : 0;
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (mat[x][y] == '.') {
				int lo = 0;
				int hi = min(x, min(y, min(n - 1 - x, n - 1 - y)));
				int v = 0;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (getSum(x - mid + 1, y - mid + 1, x + mid + 1, y + mid + 1) == 0) {
						v = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				val[x][y] = 2 * v + 1;
			}
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (mat[x][y] == '.') {
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (inside(nx, n) && inside(ny, n)) {
						if (mat[nx][ny] == '.') {
							E.push_back((edge) {getID(x, y, n), getID(nx, ny, n), min(val[x][y], val[nx][ny])});
						}
					}
				}
			}
		}
	}
	int maxID = getID(n - 1, n - 1, n);
	for (int i = 0; i <= maxID; i++) {
		parent[i] = i;
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		if (join(E[i].from, E[i].to)) {
			G[E[i].from].push_back(make_pair(E[i].to, E[i].val));
			G[E[i].to].push_back(make_pair(E[i].from, E[i].val));
		}
	}
	for (int i = 0; i <= maxID; i++) {
		visited[i] = false;
	}
	for (int l = 0; l < LOG; l++) {
		for (int i = 0; i <= maxID; i++) {
			par[l][i] = -1;
			minEdge[l][i] = -1;
		}
	}
	for (int i = 0; i <= maxID; i++) {
		if (!visited[i]) {
			dfs(i, -1, -1);
			componentCount++;
		}
	}

	int q, ra, rb, ca, cb;
	int ida, idb;
	cin >> q;
	while (q--) {
		cin >> ra >> ca >> rb >> cb;
		ida = getID(ra - 1, ca - 1, n);
		idb = getID(rb - 1, cb - 1, n);
		if (component[ida] != component[idb]) {
			cout << "0\n";
		} else {
			cout << getMinEdge(ida, idb) << "\n";
		}
	}
}
