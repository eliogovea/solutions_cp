#include <bits/stdc++.h>

using namespace std;

int t;
int n, p[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		int ans = 2;
		int mx = 0;
		for (int i = 2; i <= 100; i++) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (p[j] % i == 0) {
					cnt += p[j];
				}
			}
			if (cnt > mx) {
                mx = cnt;
                ans = i;
			}
		}
		cout << ans << "\n";
	}
}
