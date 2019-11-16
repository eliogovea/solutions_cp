// Problem: pace=1&num=1353
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int dp[15][100];

int main() {
	dp[0][0] = 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j <= 9 * i; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[i + 1][j + k] += dp[i][j];
			}
		}
	}
	dp[9][1]++;
	int s;
	cin >> s;
	cout << dp[9][s] << "\n";
}
