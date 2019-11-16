#include <bits/stdc++.h>

using namespace std;

const int N = 2002;

int r, c;
int p, f;

int sump[N][N];
int sumf[N][N];

inline int getp(int x, int y, int l) {
	return sump[x][y] - sump[x][y - l] - sump[x - l][y] + sump[x - l][y - l];
}

inline int getf(int x, int y, int l) {
	return sumf[x][y] - sumf[x][y - l] - sumf[x - l][y] + sumf[x - l][y - l];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> r >> c >> p >> f;
	while (p--) {
		int x, y;
		cin >> x >> y;
		sump[x][y]++;
	}
	while (f--) {
		int x, y;
		cin >> x >> y;
		sumf[x][y]++;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			sump[i][j] += sump[i - 1][j] + sump[i][j - 1] - sump[i - 1][j - 1];
			sumf[i][j] += sumf[i - 1][j] + sumf[i][j - 1] - sumf[i - 1][j - 1];
		}
	}

	int ansff = -1;
	int ansx;
	int ansy;
	int anslen;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (getp(i, j, 1) > 0) {
				continue;
			}
			int lo = 1;
			int hi = min(i, j);
			int len = 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (getp(i, j, mid) == 0) {
					len = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			int ff = getf(i, j, len);

			if (ff < ansff) {
				continue;
			}

			lo = 1;
			hi = len;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (getf(i, j, mid) == ff) {
					len = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			if (ff > ansff || (ff == ansff && len < anslen)) {
				ansff = ff;
				anslen = len;
				ansx = i - len;
				ansy = j - len;
			}
		}
	}
	cout << ansx << " " << ansy << "\n";
	cout << anslen << "\n";
	cout << ansff << "\n";
}
