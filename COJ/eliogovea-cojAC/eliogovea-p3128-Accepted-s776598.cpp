#include <bits/stdc++.h>

using namespace std;

int tc, n, ans, a[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i <= 1000; i++) {
			a[i] = 0;
		}
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			a[x]++;
		}
		ans = -1;
		for (int i = 0; i <= 1000; i++) {
			if (a[i]) {
				for (int j = 0; j < i; j++) {
					if (a[j]) {
						if (ans == -1 || ((i & j) > ans)) {
							ans = (i & j);
						}
					}
				}
				if (a[i] > 1 && ans < i) {
					ans = i;
				}
			}
		}
		cout << ans << "\n";
	}
}