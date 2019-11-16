#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000009;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

const int N = 105;
const int R = 25;

int n, t, r;
int dp[N][N][R];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> r;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j <= t; j++) {
			for (int k = 0; k < r; k++) {
				dp[i + 1][j][k] = dp[i][j][k];
			}
		}
		for (int j = 0; j < t; j++) {
			for (int k = 0; k < r; k++) {
				add(dp[i + 1][j + 1][(k + x) % r], dp[i][j][k]);
			}
		}
	}
	cout << dp[n][t][0] << "\n";
	return 0;
}
