#include <iostream>

using namespace std;

int tc, n, a[1005], b[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			if (mx < a[i] + b[i]) {
				mx = a[i] + b[i];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += mx - a[i] - b[i];
		}
		cout << ans << "\n";
	}
}
