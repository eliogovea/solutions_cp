#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

const int N = 1000;

int dp[5][N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		if (dp[0][i]) {
			add(dp[1][i + 1], dp[0][i]);
			add(dp[2][i + 1], dp[0][i]);
			add(dp[0][i + 1], dp[0][i]);
			add(dp[0][i + 2], dp[0][i]);
		}
		if (dp[1][i]) {
			add(dp[0][i + 2], dp[1][i]);
			add(dp[2][i + 1], dp[1][i]);
		}
		if (dp[2][i]) {
			add(dp[0][i + 2], dp[2][i]);
			add(dp[1][i + 1], dp[2][i]);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[0][n] << "\n";
	}
}
