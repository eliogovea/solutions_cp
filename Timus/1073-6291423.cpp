// Problem: pace=1&num=1073
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 60005;

int n;
int dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 1; i * i <= n; i++) {
		int x = i * i;
		for (int j = 0; j + x <= n; j++) {
			if (dp[j + x] > dp[j] + 1) {
				dp[j + x] = dp[j] + 1;
			}
		}
	}
	cout << dp[n] << "\n";
}
