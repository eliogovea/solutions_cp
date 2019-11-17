// Problem: pace=1&num=1017
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			for (int k = 0; k < i; k++) {
				dp[j + i][i] += dp[j][k];
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += dp[n][i];
	}
	cout << ans << "\n";
}