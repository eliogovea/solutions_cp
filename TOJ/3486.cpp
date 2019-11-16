#include <bits/stdc++.h>

using namespace std;

int tc, n, m;
double dp[105][605];

int main() {
	dp[0][0] = 1.0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= 6 * i; j++) {
			for (int k = 1; k <= 6; k++) {
				dp[i + 1][j + k] += dp[i][j] * 1.0 / 6.0;
			}
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		cout << fixed << dp[n][m] << "\n";
	}
}
