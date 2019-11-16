#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int N = 105;

int r, c, k;
int a[N][N], dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			for (int x = i + 1; x <= r; x++) {
				for (int y = j + 1; y <= c; y++) {
					if (a[x][y] != a[i][j]) {
						dp[x][y] += dp[i][j];
						if (dp[x][y] > mod) {
							dp[x][y] -= mod;
						}
					}
				}
			}
		}
	}
	cout << dp[r][c] << "\n";
}
