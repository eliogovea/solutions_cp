#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, s;
double x[N], y[N];
double dist[N][N];
double dp[N + 2][(1 << N) + 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		for (int j = 0; j < n; j++) {
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			dist[i][j] = dist[j][i] = sqrt(dx * dx + dy * dy);
		}
	}
	cin >> s; s--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j] = 1e10;
		}
	}
	dp[s][1 << s] = 0.0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++) {
					if (!(i & (1 << k))) {
						if (dp[k][i | (1 << k)] > dp[j][i] + dist[j][k]) {
							dp[k][i | (1 << k)] = dp[j][i] + dist[j][k];
						}
					}
				}
			}
		}
	}
	double ans = 1e10;
	for (int i = 0; i < n; i++) {
		if (ans > dp[i][(1 << n) - 1]) {
			ans = dp[i][(1 << n) - 1];
		}
	}
	cout.precision(2);
	cout << fixed << ans << "\n";
}
