#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, k;
long long x[N], w[N];
long long cost[N][N];
long long dp[N][N];
long long pos[N][N];

void solve(int g, int l, int r, int pl, int pr) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	dp[g][mid] = -1;
	pos[g][mid] = -1;
	for (int i = pl; i < mid && i <= pr; i++) {
		if (dp[g][mid] == -1 || dp[g][mid] > dp[g - 1][i] + cost[i + 1][mid]) {
			dp[g][mid] = dp[g - 1][i] + cost[i + 1][mid];
			pos[g][mid] = i;
		}
	}
	solve(g, l, mid - 1, pl, pos[g][mid]);
	solve(g, mid + 1, r, pos[g][mid], pr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				cost[j][i] = cost[j + 1][i] + w[j] * (x[i] - x[j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[1][i] = cost[1][i];
			pos[1][i] = 0;
		}
		long long ans = dp[1][n];
		for (int i = 2; i <= k; i++) {
			solve(i, i, n, i - 1, n);
			ans = min(ans, dp[i][n]);
		}
		cout << ans << "\n";
	}
}
