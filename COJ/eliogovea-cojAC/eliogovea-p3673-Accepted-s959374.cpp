#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int n, m, x;
string s;
int bad[15][15];

int dp[100005][2][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> s >> m;
	while (m--) {
		cin >> x;
		bad[x / 10][x % 10] = true;
	}
	for (int i = 0; i < n; i++) {
		s[i] -= '0';
	}
	for (int i = 0; i < s[0]; i++) {
		dp[1][0][i] = 1;
	}
	dp[1][1][s[0]] = 1;
	for (int i = 1; i < n; i++) {
		//igual
		for (int j = 0; j < 10; j++) {
			if (dp[i][1][j]) {
				for (int k = 0; k < s[i]; k++) {
					if (!bad[j][k]) {
						add(dp[i + 1][0][k], dp[i][1][j]);
					}
				}
				if (!bad[j][s[i]]) {
					add(dp[i + 1][1][s[i]], dp[i][1][j]);
				}
			}
		}
		//menor
		for (int j = 0; j < 10; j++) {
			if (dp[i][0][j]) {
				for (int k = 0; k < 10; k++) {
					if (!bad[j][k]) {
						add(dp[i + 1][0][k], dp[i][0][j]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		add(ans, dp[n][0][i]);
		add(ans, dp[n][1][i]);
	}
	add(ans, MOD - 1);
	cout << ans << "\n";
}
