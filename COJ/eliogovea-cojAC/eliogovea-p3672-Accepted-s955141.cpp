#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 5002;

int n;
string s;
int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l + 1; r < n; r++) {
			dp[l][r] = min((s[l] == s[r] ? dp[l + 1][r - 1] : INF), 1 + min(dp[l + 1][r], dp[l][r - 1]));
		}
	}
	cout << dp[0][n - 1] << "\n";
}
