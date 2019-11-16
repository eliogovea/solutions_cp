#include <bits/stdc++.h>

using namespace std;

int n, m;
int g[305][305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
			}
		}
		for (int c = 1; c <= m; c++) {
			for (int r = 2; r <= n; r++) {
				g[r][c] = max(g[r - 2][c] + g[r][c], g[r - 1][c]);
			}
			if (c > 1) {
				g[n][c] = max(g[n][c - 2] + g[n][c], g[n][c - 1]);
			}
		}
		cout << g[n][m] << "\n";
	}
}
