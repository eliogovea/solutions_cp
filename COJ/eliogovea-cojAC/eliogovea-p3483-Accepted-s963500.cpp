#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int n, k;
bool graph[N][N];
int subTreeSize[N];
int dp[N][N][N];
vector <int> sons[N];
int ans = 0;

void dfs(int u, int p) {
	subTreeSize[u] = 1;
	for (int i = 0; i < n; i++) {
		if (i != p && graph[u][i]) {
			sons[u].push_back(i);
			dfs(i, u);
			subTreeSize[u] += subTreeSize[i];
		}
	}
	// DP
	dp[u][0][1] = 1;
	int total = 1;
	for (int i = 0; i < sons[u].size(); i++) {
		int id = sons[u][i];
		for (int size = 1; size <= total; size++) {
			dp[u][i + 1][size] += dp[u][i][size];
				for (int x = 1; x <= subTreeSize[id]; x++) {
						assert(size + x <= n);
						dp[u][i + 1][size + x] += dp[u][i][size] * dp[id][sons[id].size()][x];
				}
		}
		total += subTreeSize[id];
	}
	ans += dp[u][sons[u].size()][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	k = n - k;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		graph[x][y] = graph[y][x] = true;
	}
	dfs(0, -1);
	cout << ans << "\n";
}
