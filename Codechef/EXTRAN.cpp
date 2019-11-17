#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		if (a[0] + 1 < a[1]) {
			cout << a[0] << "\n";
		} else if (a[n - 1] - 1 > a[n - 2]) {
			cout << a[n - 1] << "\n";
		} else {
			for (int i = 1; i < n; i++) {
				if (a[i] == a[i - 1]) {
					cout << a[i] << "\n";
					break;
				}
			}
		}
	}
}

