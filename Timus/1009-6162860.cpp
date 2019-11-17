// Problem: pace=1&num=1009
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n, k;
long long dp[50][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < k; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < k; j++) {
			for (int l = 0; l < k; l++) {
				dp[i][j] += dp[i - 1][l];
			}
		}
		for (int l = 1; l < k; l++) {
			dp[i][0] += dp[i - 1][l];
		}
	}
	int ans = 0;
	for (int i =0; i < k; i++) {
		ans += dp[n][i];
	}
	cout << ans << "\n";
}