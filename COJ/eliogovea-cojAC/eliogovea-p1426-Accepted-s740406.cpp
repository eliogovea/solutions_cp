#include <iostream>

using namespace std;

int n;
string a, b;

int la, lb, ans, dp[110][20010], cnt[110][20010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		la = a.size();
		lb = b.size();
		ans = -1;
		for (int i = 0; i < lb; i++)
			for (int j = 0; j < la; j++) {
				if (b[i] == a[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					cnt[i + 1][j + 1] = cnt[i][j] + 1;
				} else {
					dp[i + 1][j + 1] = dp[i + 1][j];
					cnt[i + 1][j + 1] = cnt[i + 1][j] + 1;
				}
				if (i + 1 == lb && dp[i + 1][j + 1] == lb)
					if (ans == -1 || ans > cnt[i + 1][j + 1])
						ans = cnt[i + 1][j + 1];
			}
		cout << ans << "\n";
	}
}