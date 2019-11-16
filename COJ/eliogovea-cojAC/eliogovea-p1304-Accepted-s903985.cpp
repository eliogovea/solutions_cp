#include <bits/stdc++.h>

using namespace std;

int n;
double p[25][25];
double dp[(1 << 20) + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
			p[i][j] /= 100.0;
		}
	}
	dp[0] = 1.0;
	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				pos++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) {
				dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] * p[pos][i]);
			}
		}
	}
	double ans = dp[(1 << n) - 1] * 100.0;
	char chans[20];
	sprintf(chans, "%.10lf", ans);
	int x = strlen(chans) - 10;
	for (int i = 0; i < x + 3; i++) {
		cout << chans[i];
	}
	cout << "\n";


}
