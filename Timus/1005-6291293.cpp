// Problem: pace=1&num=1005
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n, a[25];
int sum[1 << 21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//froepen("dat.txt", "r", stdin);
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		t += a[i];
	}
	int ans = -1;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum[i] = sum[i ^ (1 << j)] + a[j];
				break;
			}
		}
		if (ans == -1 || abs((t - sum[i]) - sum[i]) < ans) {
			ans = abs((t - sum[i]) - sum[i]);
		}
	}
	cout << ans << "\n";
}
