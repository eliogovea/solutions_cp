#include <bits/stdc++.h>

using namespace std;

const int N = 405;

int n;
int a[N][N];
int d1[N][N], d2[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d1[i][j] = a[i][j] + d1[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			d2[i][j] = a[i][j] + d2[i - 1][j + 1];
		}
	}
	int ans = 0;
	int x1, x2, y1, y2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 1; i + l - 1 <= n && j + l - 1 <= n; l++) {
				x1 = i + l - 1;
				y1 = j + l - 1;
				x2 = i + l - 1;
				y2 = j;
				int a = d1[x1][y1] - d1[i - 1][j - 1];
				int b = d2[x2][y2] - d2[i - 1][j + l - 1 + 1];
				if (a - b > ans) {
                    //cout << i << " " << j << " " << l << "\n";
					ans = a - b;
				}
			}
		}
	}
	cout << ans << "\n";
}
