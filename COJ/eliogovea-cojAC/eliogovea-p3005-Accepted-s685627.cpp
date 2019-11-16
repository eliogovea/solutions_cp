//============================================================================
// Name        : 3005.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

int n, m, col[MAXN], cnt[4], ans;
vector<int> G[MAXN];

bool ok = true;

void dfs(int u, int c) {
	if (!ok) return;
	col[u] = c;
	cnt[c]++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (col[v] == c) ok = false;
		if (!col[v]) dfs(v, (c == 1) ? 2 : 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!col[i]) {
			cnt[1] = cnt[2] = 0;
			dfs(i, 1);
			ans += max(cnt[1], cnt[2]);
		}
	if (!ok) cout << "-1\n";
	else cout << ans << "\n";
}
