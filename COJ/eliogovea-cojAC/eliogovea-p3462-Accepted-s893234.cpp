#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int t;
int n;
int s[N];
vector <int> g[N];

bool dfs_mark[N];

void dfs(int u) {
	dfs_mark[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
        if (!dfs_mark[g[u][i]]) {
            dfs(g[u][i]);
        }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			dfs_mark[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			if (i != s[i]) {
                g[s[i]].push_back(i);
                g[i].push_back(s[i]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!dfs_mark[i]) {
				dfs(i);
				ans++;
			}
		}
		cout << ans << "\n";
	}
}
