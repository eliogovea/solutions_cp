#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	string s;
	cin >> s;
	int n = s.size();
	vector <vector <bool> > dp(n, vector <bool> (n, false));
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i + 1 < n; i++) {
		dp[i][i + 1] = true;
	}
	for (int l = 3; l <= n; l++) {
		for (int x = 0; x + l - 1 < n; x++) {
			int y = x + l - 1;
			int sum1 = s[x] - '0' + s[y] - '0';
			int sum2 = s[x + 1] - '0' + s[y - 1] - '0';
			if (dp[x + 1][y - 1] && sum1 == sum2) {
				dp[x][y] = true;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (dp[x][y] ? "yes" : "no") << "\n";
	}
}
