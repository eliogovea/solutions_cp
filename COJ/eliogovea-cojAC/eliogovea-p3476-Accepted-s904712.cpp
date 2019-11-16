#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

const int MOD = 1000000007;

inline int add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int n, m;
int C[N + 5][N + 5];

int dp[N][N][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dp[0][0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
            if (i + 1 <= n) {
                add(dp[i + 1][j][0], mul(dp[i][j][0], n - i));
                add(dp[i + 1][j][0], mul(dp[i][j][1], n - i));
            }
			if (j + 1 <= m) {
                add(dp[i][j + 1][1], mul(dp[i][j][0], m - j));
			}
		}
	}
	int ans = 0;
	add(ans, dp[n][m][0]);
	add(ans, dp[n][m][1]);
	cout << ans << "\n";
}
