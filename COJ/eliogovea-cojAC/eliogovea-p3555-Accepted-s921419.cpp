#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
bool g[N][N];

inline int id(int x) {
	if (x > n) {
		x -= n;
	}
	return x;
}

int dp[2 * N][2 * N][2];
int a[2 * N][2 * N][2];
int b[2 * N][2 * N][2];
int c[2 * N][2 * N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = true;
	}
	for (int i = 1; i <= 2 * n; i++) {
		dp[i][i][0] = dp[i][i][1] = true;
	}
	for (int l = 1; l < n; l++) {
		for (int i = 1; i + l - 1 <= 2 * n; i++) {
			int j = i + l - 1;
			if (dp[i][j][0]) {
                //cout << i << " " << j << " 0\n";
				if (g[id(i)][id(i - 1)]) {
					a[i - 1][j][0] = i;
					b[i - 1][j][0] = j;
					c[i - 1][j][0] = 0;
					dp[i - 1][j][0] = true;
				}
				if (g[id(i)][id(j + 1)]) {
					a[i][j + 1][1] = i;
					b[i][j + 1][1] = j;
					c[i - 1][j + 1][1] = 0;
					dp[i][j + 1][1] = true;
				}
			}
			if (dp[i][j][1]) {
                //cout << i << " " << j << " 1\n";
				if (g[id(j)][id(i - 1)]) {
					a[i - 1][j][0] = i;
					b[i - 1][j][0] = j;
					c[i - 1][j][0] = 1;
					dp[i - 1][j][0] = true;
				}
				if (g[id(j)][id(j + 1)]) {
					a[i][j + 1][1] = i;
					b[i][j + 1][1] = j;
					c[i][j + 1][1] = 1;
					dp[i][j + 1][1] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][i + n - 1][0] || dp[i][i + n - 1][1]) {
			ans = i;
			break;
		}
	}
	if (!ans) {
		cout << "-1\n";
		return 0;
	}
	int x = ans;
	int y = x + n - 1;
	int z = 0;
	if (!dp[x][y][0]) {
		z = 1;
	}

	vector <int> path;
	while (x != y) {
		path.push_back(z == 0 ? id(x) : id(y));
		int nx = a[x][y][z];
		int ny = b[x][y][z];
		int nz = c[x][y][z];
		x = nx;
		y = ny;
		z = nz;
	}
	path.push_back(x);
	assert(path.size() == n);
	for (int i = 0; i < n; i++) {
		cout << path[i] << "\n";
	}
}
