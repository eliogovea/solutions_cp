#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull n, k, dp[20][3];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	dp[1][0] = (ull)(k - 1);
	dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = (k - 1ll) * (dp[i - 1][0] + dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][0] + dp[n][1] << endl;
}
