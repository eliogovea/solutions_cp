#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int INF = 1e9;

int n, k;
int a[N], b[N];
int dp[N][N][4];

const int bits[] = {0, 1, 1};

int solve(int row, int cnt, int mask) {
    if (cnt > row) {
        return INF;
    }
    if (bits[mask] > cnt) {
        return INF;
    }
	if (row == 0) {
		if (cnt == 0) {
			return 0;
		}
		return INF;
	}
	if (dp[row][cnt][mask] != INF) {
		return dp[row][cnt][mask];
	}
	if (mask == 0) {
		int x = solve(row - 1, cnt, 0);
		int y = solve(row - 1, cnt, 1);
		int z = solve(row - 1, cnt, 2);
		return dp[row][cnt][mask] = min(x, min(y, z));
	}
	if (mask == 1 && cnt > 0) {
		int x = solve(row - 1, cnt - 1, 0);
		int y = solve(row - 1, cnt - 1, 1);
		return dp[row][cnt][mask] = a[row] + min(x, y);
	}
	if (mask == 2 && cnt > 0) {
		int x = solve(row - 1, cnt - 1, 0);
		int y = solve(row - 1, cnt - 1, 2);
		return dp[row][cnt][mask] = b[row] + min(x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) {
			break;
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			sum += a[i] + b[i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				for (int l = 0; l < 3; l++) {
					dp[i][j][l] = INF;
				}
			}
		}
		int x = solve(n, k, 0);
		if (k > 1) {
            int tmp = solve(n, k, 1);
            if (tmp < x) {
                x = tmp;
            }
            tmp = solve(n, k, 2);
            if (tmp < x) {
                x = tmp;
            }
		}
		int ans = sum - x;
		cout << ans << "\n";
	}
}
