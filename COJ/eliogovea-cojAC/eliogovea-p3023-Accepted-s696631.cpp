#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <bitset>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int N = 100;

int n, k, cnt;
double dp[N + 5][15];

int main() {
	//freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	while (cin >> k >> n) {
		cnt = 0;
		for (int i = 0; i <= k; i++) dp[1][i] = 1;
		for (int i = 2; i <= n; i++) {
		    for (int j = 0; j <= k; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
				if (j + 1 <= k) dp[i][j] += dp[i - 1][j + 1];
				//cout << i << " " <<  j << " " << dp[i][j] << "\n";
			}
			while (cnt < n && dp[i][k / 2] > k + 1.0) {
				cnt++;
				for (int j = 0; j <= k; j++)
					dp[i][j] /= (k + 1.0);
			}
		}
		for (; cnt < n; cnt++) {
			for (int i = 0; i <= k; i++)
				dp[n][i] /= (k + 1.0);
		}
		long double a = 0, b = 1.0;
		for (int i = 0; i <= k; i++) a += dp[n][i];
		a *= 1e2;
		cout.precision(5);
		cout << fixed << a << "\n";
	}
}
