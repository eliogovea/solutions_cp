#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	const int N = 2024;
	vector <bool> found(N);

	vector <int> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (found[values[i] ^ values[j]]) {
				cout << "YES\n";
				return 0;
			}
		}
		found[values[i] ^ x] = true;
	}
	cout << "NO\n";
	return 0;
}
