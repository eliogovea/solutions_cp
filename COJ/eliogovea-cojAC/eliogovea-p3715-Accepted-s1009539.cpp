#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
vector <pair <int, int> > g[N];
bool visited[N];

void dfs(int u, int limit) {
	visited[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].first;
		int b = g[u][i].second;
		if (b >= limit && !visited[v]) {
			dfs(v, limit);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		vector <int> v;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			g[x].push_back(make_pair(y, z));
			g[y].push_back(make_pair(x, z));
			v.push_back(z);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		dfs(1, -1);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int lo = 0;
		int hi = v.size() - 1;
		int pos = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			for (int i = 0; i < n; i++) {
				visited[i] = false;
			}
			dfs(1, v[mid]);
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (!visited[i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				pos = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << v[pos] << "\n";
	}

}
