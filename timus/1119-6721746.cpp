// Problem: pace=1&num=1119
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int INF = 1e9;

int n, m, k;
bool mark[N][N];
double dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0, x, y; i < k; i++) {
		cin >> x >> y;
		mark[x][y] = true;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0.0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i + 1 <= n) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 100.0);
			}
			if (j + 1 <= m) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 100.0);
			}
			if (i + 1 <= n && j + 1 <= m && mark[i + 1][j + 1]) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 100.0 * sqrt(2.0));
			}
		}
	}
	int ans = dp[n][m];
	if (dp[n][m] - (double)ans >= 0.5) {
        ans++;
	}
	cout << ans << "\n";
}
