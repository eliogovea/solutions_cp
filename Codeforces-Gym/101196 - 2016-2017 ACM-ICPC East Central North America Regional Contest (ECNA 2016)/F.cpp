// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196F

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = 5e8;

int n;
int val[N];
int dp[N][N];
int gcd[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int a = 0; a <= 1000; a++) {
		gcd[a][0] = gcd[0][a] = a;
	}
	for (int a = 1; a <= 1000; a++) {
		for (int b = 1; b <= a; b++) {
			gcd[a][b] = gcd[b][a] = gcd[b][a % b];
			//assert(gcd[a][b] == __gcd(a, b));
		}
	}
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> val[i];
		}
		for (int l = 1; l <= 2; l++) {
			for (int s = 0; s < n; s++) {
                int e = (s + l - 1) % n;
				dp[s][e] = 0;
			}
		}
		for (int l = 3; l <= n; l++) {
			for (int s = 0; s < n; s++) {
				int e = (s + l - 1) % n;
				dp[s][e] = INF;
				for (int m = (s + 1) % n; m != e; m = (m + 1) % n) {
					dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e] + gcd[val[s]][val[e]]);
				}
			}
		}
		int ans = INF;
		for (int s = 0; s < n; s++) {
			for (int e = s + 1; e < n; e++) {
                ans = min(ans, dp[s][e] + dp[e][s] + gcd[val[s]][val[e]]);
			}
		}
		cout << ans << "\n";
	}
}
