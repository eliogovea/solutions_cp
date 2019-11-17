#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		int mn = 5;
		int mx = 2;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		if (mn > 2 && mx == 5 && sum >= 4 * n) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

