#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int t;
string s;
int dp[5][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		int n = s.size();
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 3; j++) {
				dp[j][i] = dp[j][i - 1];
				if (j != 0 && s[i - 1] == "CAT"[j - 1]) {
					dp[j][i] += dp[j - 1][i - 1];
				}
			}
		}
		cout << dp[3][n] << "\n";
	}
}
