#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int t;
double pv, pm;
double dp[N + 5][N + 5][N + 5];

bool primo(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 2; i <= N; i++) {
		p[i] = primo(i);
	}
	cin >> t;
	while (t--) {
		cin >> pv >> pm;;
		pv /= 100.0;
		pm /= 100.0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				for (int k = 0; k <= N; k++) {
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1.0;
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k <= i; k++) {
					dp[i + 1][j][k] += dp[i][j][k] * (1.0 - pv) * (1.0 - pm);
					dp[i + 1][j + 1][k] += dp[i][j][k] * pv * (1.0 - pm);
					dp[i + 1][j][k + 1] += dp[i][j][k] * (1.0 - pv) * pm;
					dp[i + 1][j + 1][k + 1] += dp[i][j][k] * pv * pm;
				}
			}
		}
		double ans = 0.0;
		for (int i = 0; i <= 18; i++) {
			for (int j = 0; j <= 18; j++) {
				if (p[i] || p[j]) {
					ans += dp[18][i][j];
				}
			}
		}
		cout.precision(10);
		cout << fixed << ans << "\n";
	}
}
