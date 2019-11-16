#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

bool solved[N][N];
bool dp[N + 5][N + 5];

bool solve(int n, int l) {
	if (solved[n][l]) {
		return dp[n][l];
	}
	if (n == 0) {
		return false;
	}
	solved[n][l] = true;
	int hi = (l == 0) ? n - 1 : min(2 * l, n);
	for (int c = 1; c <= hi; c++) {
		if (!solve(n - c, c)) {
			dp[n][l] = true;
			return true;
		}
	}
	dp[n][l] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (solve(n, 0) ? "Ron" : "Harry") << " wins\n";
	}
}
