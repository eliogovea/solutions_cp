#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[30][30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		int x = 1;
		while (x * x < n) {
			x++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				a[i][j]--;
			}
		}
		bool ok = true;
		for (int row = 0; row < n; row++) {
			vector <bool> used(x, false);
			for (int i = 0; i < n; i++) {
				if (used[a[row][i]]) {
					ok = false;
					break;
				}
				used[a[row][i]] = true;
 			}
			if (!ok) {
				break;
			}
		}
		if (!ok) {
			cout << "no\n";
			continue;
		}
		for (int col = 0; col < n; col++) {
			vector <bool> used(x, false);
			for (int i = 0; i < n; i++) {
				if (used[a[i][col]]) {
					ok = false;
					break;
				}
				used[a[i][col]] = true;
			}
			if (!ok) {
				break;
			}
		}
		if (!ok) {
			cout << "no\n";
			continue;
		}
		for (int i = 0; i < x && ok; i++) {
			for (int j = 0; j < x && ok; j++) {
				vector <bool> used(x, false);
				for (int ii = 0; ii < x && ok; ii++) {
					for (int jj = 0; jj < x && ok; jj++) {
						if (used[a[i * x + ii][j * x + jj]]) {
							ok = false;
							break;
						}
						used[a[i * x + ii][j * x + jj]] = true;
					}
				}
			}
		}
		cout << (ok ? "yes" : "no") << "\n";
	}
}
