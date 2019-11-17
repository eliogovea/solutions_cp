#include <bits/stdc++.h>

using namespace std;

int t;
int n;
string a, b;
int w[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] == b[i]);
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			cin >> w[i];
		}
		if (cnt == n) {
            ans = w[n];
		} else {
            for (int i = 0; i <= cnt; i++) {
                ans = max(ans, w[i]);
            }
		}
		cout << ans << "\n";
	}
}

