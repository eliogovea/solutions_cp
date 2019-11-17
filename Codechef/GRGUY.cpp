#include <bits/stdc++.h>

using namespace std;

int t;
string s[2];

const int N = 1000005;

int dp[2][N];

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s[0] >> s[1];
		int n = s[0].size();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				dp[j][i] = INF;
			}
		}
		dp[0][0] = dp[1][0] = 0;
		for (int i = 0; i < n; i++) {
			if (dp[0][i] > dp[1][i] + 1) {
					dp[0][i] = dp[1][i] + 1;
			}
			if (dp[1][i] > dp[0][i] + 1) {
					dp[1][i] = dp[0][i] + 1;
			}
			for (int j = 0; j < 2; j++) {
				if (i == 0 || (s[j][i - 1] == '.')) {
					int a = j;
					int b = i + 1;
					if (s[a][b - 1] == '.' && dp[a][b] > dp[j][i]) {
						dp[a][b] = dp[j][i];
					}
					a = j ^ 1;
					b = i + 1;
					if (s[a][b - 1] == '.' && dp[a][b] > dp[j][i] + 1) {
						dp[a][b] = dp[j][i] + 1;
					}
				}
			}
		}
		int id = 0;
		if (dp[1][n] < dp[id][n]) {
			id = 1;
		}
		if (dp[id][n] == INF) {
			cout << "No\n";
		} else {
			cout << "Yes\n" << dp[id][n] << "\n";
		}
	}
}

