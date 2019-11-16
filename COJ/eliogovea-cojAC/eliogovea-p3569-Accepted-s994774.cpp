#include <bits/stdc++.h>

using namespace std;

inline int value(char ch) {
	if (ch == 'M') {
		return 1;
	}
	if (ch == 'F') {
		return 2;
	}
	if (ch == 'B') {
		return 3;
	}
	return 0;
}

int n;
string s;
int dp[2 + 1][4 * 4 + 1][4 * 4 + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//assert(freopen("dat.txt", "r", stdin));
	cin >> n >> s;
	int cur = 0;
	for (int x = 0; x < 4 * 4; x++) {
		for (int y = 0; y < 4 * 4; y++) {
			dp[cur][x][y] = -1;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		int v = value(s[i]);
		assert(1 <= v && v <= 3);
		int next = cur ^ 1;
		for (int x = 0; x < 4 * 4; x++) {
			for (int y = 0; y < 4 * 4; y++) {
				dp[next][x][y] = -1;
			}
		}
		for (int x = 0; x < 4 * 4; x++) {
			for (int y = 0; y < 4 * 4; y++) {
				if (dp[cur][x][y] != -1) {
 					/// 1
					{
						bool used[] = {false, false, false, false};
						used[x / 4] = true;
						used[x % 4] = true;
						used[v] = true;
						int cnt = 0;
						for (int p = 1; p < 4; p++) {
							if (used[p]) {
								cnt++;
							}
						}
						dp[next][4 * (x % 4) + v][y] = max(dp[next][4 * (x % 4) + v][y], dp[cur][x][y] + cnt);
					}
					/// 2
					{
						bool used[] = {false, false, false, false};
						used[y / 4] = true;
						used[y % 4] = true;
						used[v] = true;
						int cnt = 0;
						for (int p = 1; p < 4; p++) {
							if (used[p]) {
								cnt++;
							}
						}
						dp[next][x][4 * (y % 4) + v] = max(dp[next][x][4 * (y % 4) + v], dp[cur][x][y] + cnt);
					}
				}
			}
		}
		cur = next;
	}
	int ans = 0;
	for (int x = 0; x < 4 * 4; x++) {
		for (int y = 0; y < 4 * 4; y++) {
			if (dp[cur][x][y] != -1) {
				ans = max(ans, dp[cur][x][y]);
			}
		}
	}
	cout << ans << "\n";
}
