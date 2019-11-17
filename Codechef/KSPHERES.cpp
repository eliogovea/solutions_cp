#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

const int MOD = 1e9 + 7;

inline void add(int &a, int b) {
	a += b; if (a >= MOD) a -= MOD;
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int n, m, c;
int u[N], l[N];

int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		u[x]++;
	}
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		l[x]++;
	}
	for (int i = 1; i <= c; i++) {
		dp[0][i] = mul(u[i], l[i]);
	}
	for (int i = 1; i <= c; i++) {
		add(dp[0][i], dp[0][i - 1]);
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = mul(dp[i - 1][j - 1], mul(u[j], l[j]));
		}
		for (int j = 1; j <= c; j++) {
			add(dp[i][j], dp[i][j - 1]);
		}
	}
	for (int i = 1; i <= c; i++) {
		cout << dp[i][c];
		if (i + 1 <= c) cout << " ";
	}
	cout << "\n";
}

