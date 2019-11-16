// 2014-2015 CTU Open Contest
// 100719F

#include <bits/stdc++.h>

using namespace std;

int h, w;
string s[105];
int l;
string c;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool mark[105][105][5][11];

struct state {
	int x, y, d, s;
};

bool ok[105][105][5][11];

bool dfs(int x, int y, int d, int st) {
    //cout << "dfs: " << x << " " << y << " " << d << " " << st << " " << c[st] << "\n";
	if (s[x][y] == 'E') return ok[x][y][d][st] = true;
	if (mark[x][y][d][st]) return ok[x][y][d][st];
	mark[x][y][d][st] = true;
	if (c[st] == 'S') {
		int nx = x + dx[d];
		int ny = y + dy[d];
		int nd = d;
		int nst = (st + 1) % l;
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] != 'X') {
			if (!mark[nx][ny][nd][nst]) {
				return ok[x][y][d][st] = dfs(nx, ny, nd, nst);
			} else {
                return ok[x][y][d][st] = ok[nx][ny][nd][nst];
			}
		} else {
			if (!mark[x][y][d][nst]) {
                return ok[x][y][d][st] = dfs(x, y, d, nst);
			} else {
                return ok[x][y][d][st] = ok[x][y][d][nst];
			}
		}
	} else {
		if (c[st] == 'R') {
			int nd = (d - 1 + 4) % 4;
			int nst = (st + 1) % l;
			if (!mark[x][y][nd][nst]) {
				return ok[x][y][d][st] = dfs(x, y, nd, nst);
			} else {
                return ok[x][y][d][st] = ok[x][y][nd][nst];
            }
		} else {
			int nd = (d + 1) % 4;
			int nst = (st + 1) % l;
			if (!mark[x][y][nd][nst]) {
				return ok[x][y][d][st] = dfs(x, y, nd, nst);
			} else {
                return ok[x][y][d][st] = ok[x][y][nd][nst];
			}
		}
	}
	return ok[x][y][d][st] = false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> h >> w) {
		for (int i = 0; i < h; i++) {
			cin >> s[i];
		}
		cin >> l;
		cin >> c;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				for (int k = 0; k < l; k++) {
					for (int x = 0; x < 4; x++) {
						mark[i][j][x][k] = ok[i][j][x][k] = false;
					}
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (s[i][j] != 'X') dfs(i, j, 2, 0);
			}
		}
		bool all = true;
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (s[i][j] == 'X') continue;
				if (!ok[i][j][2][0]) {
					all = false;
				} else {
					count++;
				}
			}
		}
		if (all) {
			cout << "OK\n";
		} else {
			cout << count << "\n";
		}
	}
}
