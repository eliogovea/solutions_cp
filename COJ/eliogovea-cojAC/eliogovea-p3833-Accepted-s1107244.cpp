#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double ans = 0.0;
		for (int i = 1; i <= n; i++) {
			ans += (double)n / (double)i;
		}
		cout << fixed << ans << "\n";
	}
}
