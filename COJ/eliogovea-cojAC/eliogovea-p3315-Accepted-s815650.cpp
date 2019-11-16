#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = 10005;

int n, m;
int from[M], to[M];
char type[M];

vector<int> g[N];

int tt[N];

bool dfs(int u, int t, int lim) {
	tt[u] = t;
	for (int i = 0; i < g[u].size(); i++) {
		int id = g[u][i];
		if (id > lim) {
			break;
		}
		int v = (from[id] == u) ? to[id] : from[id];
		if (tt[v] != -1 && (tt[v] != t ^ (type[id] == 'L'))) {
			return false;
		}
		if (tt[v] == -1 && !dfs(v, t ^ (type[id] == 'L'), lim)) {
			return false;
		}
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> from[i] >> to[i] >> type[i];
		g[from[i]].push_back(i);
		g[to[i]].push_back(i);
	}
	int lo = 1;
	int hi = m;
	int ans = 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		for (int i = 1; i <= n; i++) {
			tt[i] = -1;
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (tt[i] == -1) {
				ok &= dfs(i, false, mid);
				if (!ok) {
					break;
				}
			}
		}
		if (ok) {
			for (int i = 1; i <= mid; i++) {
				if (type[i] == 'T' && (tt[from[i]] != tt[to[i]])) {
					ok = false;
					break;
				}
				if (type[i] == 'L' && (tt[from[i]] == tt[to[i]])) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
}
