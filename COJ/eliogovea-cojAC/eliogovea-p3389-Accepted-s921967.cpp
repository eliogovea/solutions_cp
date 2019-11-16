#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
string a, b;

int lasta[2 * N], lastb[2 * N];

int pos['z' + 5];

int dp[2 * N][2 * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	cin >> n >> a >> b;

	a += a;
	b += b;

	for (int i = 'a'; i <= 'z'; i++) {
		pos[i] = 0;
	}
	for (int i = 1; i <= 2 * n; i++) {
		lasta[i] = pos[a[i - 1]];
		pos[a[i - 1]] = i;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		pos[i] = 0;
	}
	for (int i = 1; i <= 2 * n; i++) {
		lastb[i] = pos[b[i - 1]];
		pos[b[i - 1]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			int x = lasta[i];
			int y = lastb[j];
			int z = dp[i - 1][j - 1] + 1;
			int z1 = z;
			if (x > i - z) {
				int dist = i - x;
				if (b[j - dist - 1] != b[j - 1]) {
					z1 = i - x;
				}
			}
			int z2 = z;
			if (y > j - z) {
				int dist = j - y;
                if (a[i - dist - 1] != a[i - 1]) {
					z2 = j - y;
				}
			}

			dp[i][j] = min(z1, z2);
			//cout << i << " " << j << " " << dp[i][j] << "\n";
			ans = max(ans, dp[i][j]);
		}
	}
	if (ans > n) {
		ans = n;
	}
	cout << ans << "\n";
}
