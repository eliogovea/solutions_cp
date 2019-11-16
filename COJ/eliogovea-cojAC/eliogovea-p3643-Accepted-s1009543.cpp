#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int dp[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
	}
	for (int i = 2; i * (i + 1) / 2 <= N; i++) {
		int x = i * (i + 1) / 2;
		for (int j = x; j <= N; j++) {
			dp[j] = min(dp[j], dp[j - x] + 1);
		}
	}
	int n;
	while (cin >> n) {
		cout << dp[n] << "\n";
	}
}
