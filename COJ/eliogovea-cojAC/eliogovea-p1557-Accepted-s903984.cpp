#include <bits/stdc++.h>

using namespace std;

int t, n, x[25][25];
long long dp[(1 << 20) + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> x[i][j];
			}
		}
		for (int mask = 0; mask < (1 << n); mask++) {
			dp[mask] = 0;
		}
		dp[0] = 1;
		for (int mask = 0; mask < (1 << n) - 1; mask++) {
			int pos = 0;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					pos++;
				}
			}
			for (int i = 0; i < n; i++) {
				if (x[pos][i] && !(mask & (1 << i))) {
					dp[mask | (1 << i)] += dp[mask];
				}
			}
		}
		cout << dp[(1 << n) - 1] << "\n";
	}
}
