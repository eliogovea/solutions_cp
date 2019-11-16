#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int K = 100;
const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n;
int q, v, k;
int dp[K + 5][N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = K; j > 0; j--) {
			for (int s = i; s <= N; s++) {
				add(dp[j][s], dp[j - 1][s - i]);
			}
		}
	}
	cin >> q;
	while (q--) {
		cin >> v >> k;
		cout << dp[k][v] << "\n";
	}
}
