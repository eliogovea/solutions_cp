#include <bits/stdc++.h>

using namespace std;

int t;
int m, w;
int a[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> w;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		sort(a, a + m);
		int ans = m;
		for (int i = 0; i < m; i++) {
			if (i != 0) {
				a[i] += a[i - 1];
			}
			if (a[i] > w) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
}
