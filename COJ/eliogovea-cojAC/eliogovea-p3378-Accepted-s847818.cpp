#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline int add(int &a, int b) {
	a += b; if (a >= MOD) a -= MOD;
}

inline int f(int n) {
	while (n >= 10) {
		int x = 0;
		while (n) {
			x += n % 10;
			n /= 10;
		}
		n = x;
	}
	return n;
}

const int N = 100005;

int n, x, fx;
int dp[10][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		fx = f(x);
		for (int j = 0; j < 10; j++) {
			dp[j][i] = dp[j][i - 1];
		}
		for (int j = 0; j < 10; j++) {
			add(dp[f(j + fx)][i], dp[j][i - 1]);
		}
	}
	for (int i = 1; i <= 9; i++) {
		cout << dp[i][n] << "\n";
	}
}
