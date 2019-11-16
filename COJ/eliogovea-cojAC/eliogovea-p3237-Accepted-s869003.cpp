#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

const int INF = 1e9;

int t;
int l, n;
string s;

bool criba[N + 5];

vector <int> dp[7];
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "w", stdout);
	for (int i = 2; i * i <= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N; j += i) {
				criba[j] = true;
			}
		}
	}
	criba[0] = criba[1] = true;

	for (int l = 1; l <= 6; l++) {
		int mx = 1;
		for (int i = 0; i < l; i++) mx *= 10;
		dp[l].clear();
		dp[l].resize(mx + 5, INF);
		for (int i = 0; i < mx; i++) {
			if (!criba[i]) {
				dp[l][i] = 0;
				q.push(i);
			} else {
				dp[l][i] = INF;
			}
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i = 1; i < mx; i *= 10) {
				int d = (cur / i) % 10;
				if (d < 9) {
					int tmp = cur + i;
					if (dp[l][tmp] == INF) {
						dp[l][tmp] = dp[l][cur] + 1;
						q.push(tmp);
					}
				} else {
					int tmp = cur - 9 * i;
					if (dp[l][tmp] == INF) {
						dp[l][tmp] = dp[l][cur] + 1;
						q.push(tmp);
					}
				}
				if (d > 0) {
					int tmp = cur - i;
					if (dp[l][tmp] == INF) {
						dp[l][tmp] = dp[l][cur] + 1;
						q.push(tmp);
					}
				} else {
					int tmp = cur + 9 * i;
					if (dp[l][tmp] == INF) {
						dp[l][tmp] = dp[l][cur] + 1;
						q.push(tmp);
					}
				}
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> l >> s;
		n = 0;
		for (int i = 0; s[i]; i++) {
			n = 10 * n + s[i] - '0';
		}
		cout << dp[l][n] << "\n";
	}
}
