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
		for (int i = 0; i < n; i++) {
			cout << n + i;
			if (i + 1 < n) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

