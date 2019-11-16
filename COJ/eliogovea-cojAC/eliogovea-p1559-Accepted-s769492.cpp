#include <iostream>

using namespace std;

const int mod = 1e6;

int n, m, k;
int dp[1005][1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	while (cin >> n >> m >> k) {
		if (n == 0 && m == 0 && k == 0) {
			break;
		}
		m -= k;
		dp[0][0] = 1;
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 0;
			dp[0][i] += dp[0][i - 1];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - k - 1 >= 0) {
					dp[i][j] = (dp[i][j] - dp[i - 1][j - k - 1] + mod) % mod;
				}
			}
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= mod;
			}
		}
		cout << dp[n - 1][m] << "\n";
	}
}
