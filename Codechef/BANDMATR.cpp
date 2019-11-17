#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int t;
int n;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) {
					cnt++;
				}
			}
		}
		int need = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				need += n;
			} else {
				need += 2 * (n - i);
			}
			if (need >= cnt) {
				cout << i << "\n";
				break;
			}
		}
	}
}

