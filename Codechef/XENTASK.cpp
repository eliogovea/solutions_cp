#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 10 * 1000 + 10;

int t, n, x[N], y[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> y[i];
		}
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				ans1 += x[i];
				ans2 += y[i];
			} else {
				ans1 += y[i];
				ans2 += x[i];
			}
		}
		cout << min(ans1, ans2) << "\n";
	}
}

