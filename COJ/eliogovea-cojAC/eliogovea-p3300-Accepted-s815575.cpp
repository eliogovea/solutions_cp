#include <bits/stdc++.h>

using namespace std;

int n;
double p[1005];

double dp[102][102][102];

double solve(int l, int r, int h) {
	if (dp[l][r][h] > -0.5) {
		//cout << l << " " << r << " " << fixed << dp[l][r][h] << "\n";
		return dp[l][r][h];
	}
	double res = 1e9;
	for (int i = l; i <= r; i++) {
		double tmp = p[i] * (double)h;
		if (tmp > res) {
			continue;
		}
		if (i != l) {
			tmp += solve(l, i - 1, h + 1);
		}
		if (tmp > res) {
			continue;
		}
		if (i != r) {
			tmp += solve(i + 1, r, h + 1);
		}
		if (tmp < res) {
			res = tmp;
		}
	}
	dp[l][r][h] = res;
	//cout << l << " " << r << " " << fixed << dp[l][r][h]<< "\n";
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cout.precision(6);
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					dp[i][j][k] = -1.0;
				}
			}
		}
		double ans = solve(1, n, 1);
		cout << fixed << ans << "\n";
	}
}
