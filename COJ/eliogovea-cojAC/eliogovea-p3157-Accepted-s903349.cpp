#include <bits/stdc++.h>

using namespace std;

string s;
long long dp[5][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cin >> s;
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[2][0] = 0;
	dp[3][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			dp[j][i] = dp[j][i - 1];
		}
		if (s[i - 1] == 'C') {
			dp[1][i] += dp[0][i - 1];
		}
		if (s[i - 1] == 'O') {
			dp[2][i] += dp[1][i - 1];
		}
		if (s[i - 1] == 'W') {
			dp[3][i] += dp[2][i - 1];
		}
	}
	cout << dp[3][n] << "\n";
}
