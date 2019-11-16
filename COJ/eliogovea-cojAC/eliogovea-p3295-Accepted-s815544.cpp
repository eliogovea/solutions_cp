#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1005;

const ll inf = 1LL << 55LL;

ll n, k;
ll c[N];
ll d[N][N];
ll dp[205][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
		}
		if (k >= n) {
			cout << "0\n";
			continue;
		}
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				d[i][j] = c[j] - c[i];
			}
		}
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j + i - 1 <= n; j++) {
				d[j][j + i - 1] += d[j + 1][j + i - 1 - 1];
			}
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = inf;
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[1][i] = d[1][i];
		}
		ll ans = dp[1][n];
		for (int i = 2; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = j; l >= 1; l--) {
					int tmp = dp[i - 1][l - 1] + d[l][j];
					if (tmp < dp[i][j]) {
						dp[i][j] = tmp;
					}
				}
			}
			if (dp[i][n] < ans) {
				ans = dp[i][n];
			}
		}
		cout << ans << "\n";
	}
}
