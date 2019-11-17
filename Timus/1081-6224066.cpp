// Problem: pace=1&num=1081
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
long long dp[50][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> k;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	string ans;
	bool ok = true;
	for (int i = n; i >= 1; i--) {
		if (dp[i][0] >= k) {
			ans += '0';
		} else {
			k -= dp[i][0];
			if (dp[i][1] < k) {
				ok = false;
				break;
			}
			ans += '1';
		}
	}
	if (!ok) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}