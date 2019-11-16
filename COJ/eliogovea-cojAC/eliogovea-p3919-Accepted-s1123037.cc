#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

double dp[N][N];

double c(double x) {
	return x * (x - 1.0) / 2.0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	dp[0][x] = 1.0;
	for (int i = 0; i < n - 1; i++) {
		int t = n - i;
		for (int p = 1; p < t; p++) {
			dp[i + 1][p] += dp[i][p] * (c(t - p) + (double)p * (double)(t - p)) / c(t);
			if (p != 1) {
				dp[i + 1][p - 1] += dp[i][p] * c(p - 1) / c(t);
			}
            dp[i + 1][t] += dp[i][p] * ((double)(p - 1) / c(t));
		}
		dp[i + 1][t] += dp[i][t] * (double)(t - 1.0) / c(t);
		if (t != 1) {
            dp[i + 1][t - 1] += dp[i][t] * c(t - 1) / c(t);
		}
		for (int p = t + 1; p <= n; p++) {
            dp[i + 1][p] += dp[i][p];
		}
	}
	cout.precision(4);
	cout << fixed << dp[n - 1][y] << "\n";
}
