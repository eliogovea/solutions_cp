#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	const int A = 'Z' - 'A' + 1;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector <vector <int>> cnt(A, vector <int> (n + 1, 0));

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'A'][i + 1]++;
		}

		for (int c = 0; c < A; c++) {
			for (int i = 1; i <= n; i++) {
				cnt[c][i] += cnt[c][i - 1];
			}
		}

		vector <vector <long long>> dp(n, vector <long long> (n, -1));

		for (int i = 0; i < n; i++) {
			dp[i][i] = 0;
		}

		for (int l = 2; l <= n; l++) {
			for (int i = 0; i + l <= n; i++) {
				int j = i + l - 1;
				for (int k = i; k <= j; k++) {
					long long v = cnt[s[k] - 'A'][j + 1] - cnt[s[k] - 'A'][i] - 1;
					if (i < k) {
						v += dp[i][k - 1];
					}
					if (k < j) {
						v += dp[k + 1][j];
					}
					if (dp[i][j] == -1 || v < dp[i][j]) {
						dp[i][j] = v;
					}
				}
			}
		}

		cout << dp[0][n - 1] << "\n";
	}
}
