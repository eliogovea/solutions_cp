#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int cnt[N + 5][N + 5];
int ans[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j < i; j++) {
			cnt[i][j] = cnt[i - 1][j];
		}
		int x = i;
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				while (x % j == 0) {
					cnt[i][j]++;
					x /= j;
				}
			}
		}
		if (x > 1) {
			cnt[i][x]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		ans[i] = 1;
		cnt[i][2] -= cnt[i][5];
		cnt[i][5] = 0;
		for (int j = 2; j <= i; j++) {
			for (int k = 1; k <= cnt[i][j]; k++) {
				ans[i] = (ans[i] * j) % 10;
			}
		}
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << ans[n] << "\n";
	}
}
