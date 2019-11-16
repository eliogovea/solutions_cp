#include <bits/stdc++.h>

using namespace std;

const int N = 64;

int n;
int a[N];
long long dp[N][N][N];

int main() {
	cin >> n;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
        cin >> a[i];
		for (int c = 0; c <= i; c++) {
			for (int o = 0; o < N; o++) {
				dp[i + 1][c][o] += dp[i][c][o];
				dp[i + 1][c + 1][o | a[i]] += dp[i][c][o];
			}
		}
	}

	int mx = 0;
	long long ans = 0;
	for (int c = 1; c <= n; c++) {
		for (int o = 0; o < N; o++) {
            if (dp[n][c][o] == 0) {
                continue;
            }
			if (o / c > mx) {
				mx = o / c;
				ans = dp[n][c][o];
			} else if (o / c == mx) {
				ans += dp[n][c][o];
			}
		}
	}
	cout << ans << "\n";
}
