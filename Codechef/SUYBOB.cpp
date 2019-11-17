#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int t, n, a, q, x;
int dp[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= N; i++) {
			dp[i] = 1e9;
		}

		while (n--) {
			cin >> a;
			for (int i = a; i <= N; i++) {
				dp[i] = min(dp[i], dp[i - a] + 1);
			}
		}

		cin >> q;
		while (q--) {
			cin >> x;
			cout << dp[x] << "\n";
		}
	}
}

