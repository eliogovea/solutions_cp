// Problem: pace=1&num=1225
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

long long n, dp[50][5];

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 2][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 2][0];
	}
	cout << dp[n][0] + dp[n][1] << "\n";
}