//============================================================================
// Name        : 2355.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>

using namespace std;

const int MAXN = 105;

int n, m, a[MAXN][MAXN], ans = 1000000;

inline int get(int i1, int j1, int i2, int j2) {
	return a[i2][j2] - a[i2][j1 - 1] - a[i1 - 1][j2] + a[i1 - 1][j1 - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	for (int k = 1; k * k <= m; k++)
		if (m % k == 0) {
			int l = m / k;
			for (int i = 1; i + k - 1 <= n; i++)
				for (int j = 1; j + l - 1 <= n; j++) {
					int tmp = m - get(i, j, i + k - 1, j + l - 1);
					if (tmp < ans) ans = tmp;
				}
			for (int i = 1; i + l - 1 <= n; i++)
				for (int j = 1; j + k - 1 <= n; j++) {
					int tmp = m - get(i, j, i + l - 1, j + k - 1);
					if (tmp < ans) ans = tmp;
				}
		}
	cout << ans << "\n";
}
