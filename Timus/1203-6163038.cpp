// Problem: pace=1&num=1203
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[300005];
int dp[300005], ans;

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= 300000; i++) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < v[i].size(); j++) {
			if (dp[v[i][j] - 1] + 1 > dp[i]) {
				dp[i] = dp[v[i][j] - 1] + 1;
			}
		}
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans << "\n";
}