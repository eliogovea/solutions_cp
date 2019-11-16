#include <bits/stdc++.h>

using namespace std;

int tc, n, a[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (!ok) {
				int sum = 0;
				for (int j = i; j >= 0; j--) {
					sum += a[j];
					if (sum == 0) {
						ok = true;
					}
				}
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}
