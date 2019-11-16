//============================================================================
// Name        : 1752.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>

using namespace std;

int tc, n, w, l, x, y, a[2005][2005], ans;

inline int get(int i1, int j1, int i2, int j2) {
	return a[i2][j2] - a[i1 - 1][j2] - a[i2][j1 - 1] + a[i1 - 1][j1 - 1];
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n >> w >> l;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = 0;
		while (w--) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int lo = 0, hi = min(i, j), mid, f;
				while (lo + 1 < hi) {
					mid = (lo + hi + 1) >> 1;
					f = get(i - mid, j - mid, i, j);
					if (f <= l) lo = mid;
					else hi = mid;
				}
				lo = (lo + 1) * (lo + 1);
				if (lo > ans) ans = lo;
			}
		cout << ans << "\n";
	}
}
