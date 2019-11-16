// 3076 - The Nikola Game

#include <iostream>

using namespace std;

const int N = 1005;

int n, cost[N], dp[N][N], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	ans = -1;
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n; j - i >= 1; j--)
			if (dp[i][j] != -1 && (dp[i][j - i] == -1 || dp[i][j - i] > dp[i][j] + cost[j - i]))
				dp[i][j - i] = dp[i][j] + cost[j - i];
		for (int j = 1; j + i + 1 <= n; j++)
			if (dp[i][j] != -1 && (dp[i + 1][j + i + 1] == -1 || dp[i + 1][j + i + 1] > dp[i][j] + cost[j + i + 1]))
				dp[i + 1][j + i + 1] = dp[i][j] + cost[j + i + 1];
		if ((dp[i][n] != -1) && (ans == -1 || ans > dp[i][n])) ans = dp[i][n];
		/*for (int j = 1; j <= n; j++)
      cout << dp[i][j] << " ";
    cout << "\n";*/
	}
	cout << ans << "\n";
}


