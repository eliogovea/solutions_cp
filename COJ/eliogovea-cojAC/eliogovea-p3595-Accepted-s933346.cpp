#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <vector <int> > a(n + 5, vector <int>(n + 5, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] = 1 - a[i][j];
			a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	long long maxl = 0;
	long long ans = 0;
	int lo = 1;
	int hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool ok = false;
		int ways = 0;
		for (int i = mid; i <= n; i++) {
			for (int j = mid; j <= n; j++) {
				int sum = a[i][j] - a[i][j - mid] - a[i - mid][j] + a[i - mid][j - mid];
				if (sum == 0) {
					ok = true;
					ways++;
				}
			}
		}
		if (ok) {
			maxl = mid;
			ans = (long long)maxl * ways;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
}
