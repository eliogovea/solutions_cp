#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 10;
const int INF = 1e9;

int g[N];
vector <int> rg[N];

bool in_cycle[N];

bool visited[N];

int val[N][2];

int solve(int u, bool x) {
    // cerr << "in dfs: " << u << "\n";
	visited[u] = true;
	if (val[u][x] != -1) {
        return val[u][x];
	}
	int res = x ? 1 : 0;
	for (int i = 0; i < rg[u].size(); i++) {
		int v = rg[u][i];
		if (in_cycle[v]) {
            continue;
		}
		if (x) {
			res += solve(v, false);
		} else {
			res += max(solve(v, true), solve(v, false));
		}
	}
	val[u][x] = res;
	return res;
}
int dp[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> g[i];
		g[i]--;
		rg[g[i]].push_back(i);
	}

	for (int i = 0; i < n; i++) {
        val[i][0] = val[i][1] = -1;
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int x = i;
			visited[x] = true;
			while (!visited[g[x]]) {
				visited[g[x]] = true;
				x = g[x];
			}
			for (int y = g[x]; true; y = g[y]) {
				in_cycle[y] = true;
				if (y == x) {
					break;
				}
			}
			// cerr << i << " " << x << "\n";
			for (int y = g[x]; true; y = g[y]) {
				val[y][0] = solve(y, 0);
				val[y][1] = solve(y, 1);
				if (y == x) {
					break;
				}
			}
			// cerr << "---\n";
			// usando el primero
			dp[x][0] = -INF;
			dp[x][1] = val[x][1];
			int y;
			for (y = x; g[y] != x; y = g[y]) {
				dp[g[y]][0] = val[g[y]][0] + max(dp[y][0], dp[y][1]);
				dp[g[y]][1] = val[g[y]][1] + dp[y][0];
			}
			int v1 = dp[y][0];

			// sin usar el primero
			dp[x][0] = val[x][0];
			dp[x][1] = -INF;
			for (y = x; g[y] != x; y = g[y]) {
				dp[g[y]][0] = val[g[y]][0] + max(dp[y][0], dp[y][1]);
				dp[g[y]][1] = val[g[y]][1] + dp[y][0];
			}

			int v2 = max(dp[y][0], dp[y][1]);

			answer += max(v1, v2);
		}
	}

	cout << answer << "\n";
}
