#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 5002;

int n;
string s;
int dp[N][N];

int solve(int l, int r) {
	if (l > r || l == r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int ve = (s[l] == s[r] ? solve(l + 1, r - 1) : INF);
	int v1 = 1 + solve(l + 1, r);
	int v2 = 1 + solve(l, r - 1);
	dp[l][r] = min(ve, min(v1, v2));
	return dp[l][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, n - 1) << "\n";
}
