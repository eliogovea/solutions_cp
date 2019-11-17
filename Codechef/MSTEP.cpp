#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int t, n;
int x[N * N];
int y[N * N];
int m[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				x[m[i][j]] = i;
				y[m[i][j]] = j;
			}
		}
		long long ans = 0;
		for (int i = 2; i <= n * n; i++) {
			ans += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
		}
		cout << ans << "\n";
	}
}

