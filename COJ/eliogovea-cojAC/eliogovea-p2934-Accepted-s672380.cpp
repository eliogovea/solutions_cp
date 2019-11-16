//============================================================================
// Name        : 2934.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int MAXN = 200;

int n, r, c;
double dp[2 * MAXN + 5][MAXN + 5][MAXN + 5], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(2);
	while (cin >> n >> r >> c && (n | r | c)) {
		if ((r + c) & 1) {
			cout << "Infinite\n";
			continue;
		}
		for (int i = 0; i <= 2 * n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= n; k++)
					dp[i][j][k] = 0.0;
		ans = 0.0;
		dp[0][r][c] = 1.0;
		for (int i = 0; i < 2 * n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++) {
					int cnt = 4;
					if (j == 1 || j == n) cnt--;
					if (k == 1 || k == n) cnt--;
					double p = 1.0 / (double)cnt;
					if (j - 1 + k - 1 > i)
						for (int l = 0; l < 4; l++) {
							int a = j + dx[l];
							int b = k + dy[l];
							if (a >= 1 && a <= n && b >= 1 && b <= n)
								dp[i + 1][a][b] += p * dp[i][j][k];
						}
				}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int aux = i - 1 + j - 1;
				ans += double(aux) * dp[aux][i][j];
			}
		cout << fixed << ans << "\n";
	}
}
