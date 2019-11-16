#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 1005;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int t;
int n, m, l;

int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> l >> m;
		for (int i = 1; i <= n; i++) {
			dp[1][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			add(dp[1][i], dp[1][i - 1]);
		}
		for (int i = 2; i <= l; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = dp[i - 1][min(n, j + m)];
				add(dp[i][j], MOD - dp[i - 1][max(0, j - m - 1)]);
				add(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << dp[l][n] << "\n";
	}
}
