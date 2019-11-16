#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int N = 1000 * 1000;
	vector <int> c(N + 1);
	for (int i = 3; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			c[j]++;
		}
	}

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		cout << "Case #" << i << ": " << n - 2 - c[n] << "\n";
	}
}
