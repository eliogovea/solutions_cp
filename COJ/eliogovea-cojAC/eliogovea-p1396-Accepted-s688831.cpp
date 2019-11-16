#include <iostream>

using namespace std;

typedef unsigned long long LL;

int tc, n, k;
LL dp[101][101][101];

LL solve(LL n, LL k) {
	if ((n & 1LL) || (k == 0)) return 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int l = 0; l < k; l++)
				dp[i][j][l] = 0;
	dp[0][0][0] = 1LL;
	for (LL i = 0; i < n; i++)
		for (LL j = 0; j <= n / 2; j++) {
			for (LL l = 0; l < k; l++) {
				dp[i + 1][j + 1][(l + (1LL << i) % k) % k] += dp[i][j][l];
				if (i != n - 1) dp[i + 1][j][l] += dp[i][j][l];
			}
		}
	return dp[n][n / 2][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n >> k;
		cout << "Case " << i << ": " << solve(n, k) << "\n";
	}
}
