#include <bits/stdc++.h>

using namespace std;

const int N = 30005;
const int C = 10005;

int n, c;
vector <int> a[C];
vector <int> id[N];
vector <int> graph[C];
map <pair <int, int>, int> edges;
int degree[C];
int visited[C];
int seen[C];
int timer;

void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (visited[v] == -1) {
			dfs(v);
		}
	}
}

vector <int> bridges;

void findBridges(int root, int u, int p) {
	if (visited[u] != -1) {
		return;
	}
	visited[u] = seen[u] = timer++;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (v == p) {
			continue;
		}
		if (visited[v] == -1) {
			findBridges(root, v, u);
			seen[u] = min(seen[u], seen[v]);
			if (u == root && seen[v] > visited[u]) {
				bridges.push_back(v);
			}
		} else {
			seen[u] = min(seen[u], visited[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> c) {
		for (int i = 0; i < c; i++) {
			a[i].clear();
			degree[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			id[i].clear();
		}
		for (int i = 0; i < c; i++) {
			int cnt;
			cin >> cnt;
			while (cnt--) {
				int x;
				cin >> x;
				a[i].push_back(x);
				id[x].push_back(i);
			}
			sort(a[i].begin(), a[i].end());
		}
		edges.clear();
		for (int i = 0; i < n; i++) {
			if ((int)id[i].size() == 2) {
				degree[id[i][0]]++;
				degree[id[i][1]]++;
				edges[make_pair(id[i][0], id[i][1])]++;
				edges[make_pair(id[i][1], id[i][0])]++;
			}
		}
		for (int i = 0; i < c; i++) {
            graph[i].clear();
		}
		for (map <pair <int, int>, int>::iterator it = edges.begin(); it != edges.end(); it++) {
			int u = it->first.first;
			int v = it->first.second;
			graph[u].push_back(v);
		}
		int start = 0;
		while ((int)a[start].size() == 0) {
			start++;
		}
		assert(start < c);
		for (int i = 0; i < c; i++) {
			visited[i] = -1;
		}
		dfs(start);
		bool ok = true;
		for (int i = 0; i < c; i++) {
			if ((int)a[i].size() != 0 && visited[i] == -1) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		int odd = 0;
		int x1 = -1;
		int x2 = -1;
		for (int i = 0; i < c; i++) {
			if (degree[i] & 1) {
				odd++;
				if (odd > 2) {
					ok = false;
					break;
				}
				if (x1 == -1) {
					x1 = i;
				} else {
					x2 = i;
				}
			}
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		if (odd == 0) {
			cout << "0\n";
			continue;
		}
		int ans = n;
		if ((int)a[x1].size() == 1) {
			assert(degree[x1] == 1);
			ans = min(ans, a[x1][0]);
		} else {
			for (int i = 0; i < c; i++) {
				visited[i] = -1;
				seen[i] = -1;
			}
			timer = 0;
			bridges.clear();
			findBridges(x1, x1, -1);
			sort(bridges.begin(), bridges.end());
			for (int i = 0; i < a[x1].size(); i++) {
				int x = a[x1][i];
				if (id[x].size() == 1) {
					ans = min(ans, x);
					break;
				}
				int next = id[x][0];
				if (next == x1) {
					next = id[x][1];
				}
				int pos = lower_bound(bridges.begin(), bridges.end(), next) - bridges.begin();
				if (pos == (int)bridges.size() || bridges[pos] != next) {
					ans = min(ans, x);
					break;
				}
				if (edges[make_pair(x1, next)] > 1) {
					ans = min(ans, x);
					break;
				}
			}
		}
		if ((int)a[x2].size() == 1) {
			assert(degree[x2] == 1);
			ans = min(ans, a[x2][0]);
		} else {
			for (int i = 0; i < c; i++) {
				visited[i] = -1;
				seen[i] = -1;
			}
			timer = 0;
			bridges.clear();
			findBridges(x2, x2, -1);
			sort(bridges.begin(), bridges.end());
			for (int i = 0; i < (int)a[x2].size(); i++) {
				int x = a[x2][i];
				if ((int)id[x].size() == 1) {
					ans = min(ans, x);
					break;
				}
				int next = id[x][0];
				if (next == x2) {
					next = id[x][1];
				}
				int pos = lower_bound(bridges.begin(), bridges.end(), next) - bridges.begin();
				if (pos == (int)bridges.size() || bridges[pos] != next) {
					ans = min(ans, x);
					break;
				}
				if (edges[make_pair(x2, next)] > 1) {
					ans = min(ans, x);
					break;
				}
			}
		}
		if (ans == n) {
			ans = -1;
		}
		cout << ans << "\n";
	}
}
