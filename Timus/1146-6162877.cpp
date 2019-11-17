// Problem: pace=1&num=1146
// Verdict: Accepted

#include <iostream>
using namespace std;

int n, a[105][105], mx[105], ans = -1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			mx[0] = -1e9;
			for (int k = 1; k <= n; k++) {
				mx[k] = max(mx[k - 1] + a[i][k] - a[j - 1][k], a[i][k] - a[j - 1][k]);
				if (mx[k] > ans) {
					ans = mx[k];
				}
			}
		}
	}
	cout << ans << "\n";
}