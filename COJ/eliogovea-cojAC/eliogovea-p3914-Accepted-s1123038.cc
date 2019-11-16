#include <bits/stdc++.h>

using namespace std;

const int N = 5 * 10 * 1000 + 5;

int n, m;
vector <int> g[N];
int t[N];
int used;
bool visited[N];

int value[N];

int dfs(int u) {
	if (visited[u]) {
		return value[u];
	}
	visited[u] = true;
	int res = t[u];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		res = max(res, dfs(v));
	}
	value[u] = res;
	return res;
}

int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		p--;
		t[p] = i;
	}

	for (int i = 0; i < n; i++) {
		cnt[dfs(i)]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cnt[i];
		cout << ans << "\n";
	}
}
