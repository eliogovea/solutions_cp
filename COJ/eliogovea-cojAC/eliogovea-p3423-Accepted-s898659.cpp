#include <bits/stdc++.h>

using namespace std;

int t, n, k, a[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			a[n + i] = 360 + a[i];
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			int cur = i;
			int cnt = 0;
			while (cur < 2 * n && a[cur] < 360 + a[i]) {
				cnt++;
				cur = upper_bound(a, a + 2 * n, a[cur] + k) - a;
			}
			if (ans == -1 || cnt < ans) {
				ans = cnt;
			}
		}
		cout << ans << "\n";
	}
}
