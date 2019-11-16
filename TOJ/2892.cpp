#include <bits/stdc++.h>

using namespace std;

int tc, n, m, a[25][25];

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0, x, y; i < m; i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					a[i][j] |= (a[i][k] & a[k][j]);
				}
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i][i]) {
				ans = 0;
				break;
			}
		}
		cout << ans << "\n";
	}
}
