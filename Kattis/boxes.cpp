#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int n;
vector <int> G[N];
int P[N];
int tin[N], tout[N], timer;
int size[N];
int q, m, v[25];


void dfs(int u) {
	size[u] = 1;
	tin[u] = timer++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
		size[u] += size[v];
	}
	tout[u] = timer++;
}

inline bool ancestor(int u, int v) {
	return ((tin[u] <= tin[v]) && (tout[v] <= tout[u]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		G[P[i]].push_back(i);
	}
	dfs(0);
	cin >> q;
	while (q--) {
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			bool ok = true;
			for (int j = 0; j < m; j++) {
				if (i != j && ancestor(v[j], v[i])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans += size[v[i]];
			}
		}
		cout << ans << "\n";
	}
}
