#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

int t;
int n, m, p;
int X0, Y0;
vector <pair <int, int> > values[N][N];

int dp[N][N][1005];

int solve(int x, int y, int tm) {
	if (dp[x][y][tm] != -1) {
		return dp[x][y][tm];
	}
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
			int tmp = solve(xx, yy, tm + 1);
			int pos = lower_bound(values[xx][yy].begin(), values[xx][yy].end(), make_pair(tm + 1, -1)) - values[xx][yy].begin();
			if (pos < values[xx][yy].size() && values[xx][yy][pos].first == tm + 1) {
				tmp += values[xx][yy][pos].second;
			}
			res = max(res, tmp);
		}
	}
	dp[x][y][tm] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> m >> p;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				values[i][j].clear();
			}
		}
		cin >> X0 >> Y0;
		for (int i = 0; i < p; i++) {
			int x, y, t, v;
			cin >> x >> y >> t >> v;
			values[x][y].push_back(make_pair(t, v));
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sort(values[i][j].begin(), values[i][j].end());
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k <= 1000; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		cout << solve(X0, Y0, 0) << "\n";
	}
}
