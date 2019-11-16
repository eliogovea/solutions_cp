#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int f[12][100005];
int q, l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n) {
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= n; j++) {
				f[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 0; j <= 9; j++) {
				f[j][i] = f[j][i - 1];
				if (j == a[i]) {
					f[j][i]++;
				}
			}
		}
		cin >> q;
		while (q--) {
			cin >> l >> r;
			if (l > r) {
				swap(l, r);
			}
			int ans = 0;
			for (int i = 0; i <= 9; i++) {
				if (f[i][r] > f[i][l - 1]) {
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
}
