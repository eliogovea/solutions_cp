#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, p, x, y;
int g[N][N];

int dp[1 << N];

int val[1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[x][y]++;
		g[y][x]++;
	}
	for (int i = 0; i < n; i++) {
		val[1 << i] = i;
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int x = i & -i;
		int y = val[x];
		dp[i] = dp[i - x];
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				dp[i] -= g[y][j];
			} else {
				dp[i] += g[y][j];
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
}
