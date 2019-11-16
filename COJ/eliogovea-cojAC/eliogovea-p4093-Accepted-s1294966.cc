#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
string t[N];

bool visited[N][N][5];
char mov[N][N][5];
int px[N][N][5];
int py[N][N][5];
int pz[N][N][5];

int Q[N * N * 10 + 10];
int qh, qt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		cin >> t[x];
	}

	int sx = -1, sy = -1, ex = -1, ey = -1;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (t[x][y] == 'C') {
				sx = x;
				sy = y;
			}
			if (t[x][y] == 'E') {
				ex = x;
				ey = y;
			}
		}
	}

	if (sx == -1 || sy == -1 || ex == -1 || ey == -1) {
		// assert(false);
		cout << "-1\n";
		return 0;
	}

	int qh = 0;
	int qt = 0;

	visited[sx][sy][0] = true;

	Q[qt++] = sx;
	Q[qt++] = sy;
	Q[qt++] = 0;

	while (qh < qt) {
		int x = Q[qh++];
		int y = Q[qh++];
		int z = Q[qh++];

		assert(visited[x][y][z]);

		// cerr << x << " " << y << " " << z << "\n";

		if (z == 0) {
			if (!(0 <= x && x < n && 0 <= y && y < m)) {
				// assert(false);
				cout << "!\n";
				return 0;
			}
		} else if (z == 1) {
			if (!(0 <= x && x + 1 < n && 0 <= y && y < m)) {
				// assert(false);
				cout << "!\n";
				return 0;
			}
		} else if (z == 2) {
			if (!(0 <= x && x < n && 0 <= y && y + 1 < m)) {
				// assert(false);
				cout << "!\n";
				return 0;
			}
		} else {
			// assert(false);
			cout << "!\n";
			return 0;
		}

		if (z == 0) { // 1x1
			{ // up
				if (x - 2 >= 0 && t[x - 1][y] != '#' && t[x - 2][y] != '#') {
					int nx = x - 2;
					int ny = y;
					int nz = 1;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] = 'U';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // down
				if (x + 2 < n && t[x + 1][y] != '#' && t[x + 2][y] != '#') {
					int nx = x + 1;
					int ny = y;
					int nz = 1;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] = 'D';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}

				}
				
			}
			{ // left
				if (y - 2 >= 0 && t[x][y - 1] != '#' && t[x][y - 2] != '#') {
					int nx = x;
					int ny = y - 2;
					int nz = 2;
					
					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] = 'L';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // right
				if (y + 2 < m && t[x][y + 1] != '#' && t[x][y + 2] != '#') {
					int nx = x;
					int ny = y + 1;
					int nz = 2;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] = 'R';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}

				}
				
			}
		} else if (z == 1) { // 2x1
			{ // up
				if (x - 1 >= 0 && t[x - 1][y] != '#') {
					int nx = x - 1;
					int ny = y;
					int nz = 0;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] = 'U';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // down
				if (x + 2 < n && t[x + 2][y] != '#') {
					int nx = x + 2;
					int ny = y;
					int nz = 0;
					
					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'D';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // left
				if (y - 1 >= 0 && t[x][y - 1] != '#' && t[x + 1][y - 1] != '#') {
					int nx = x;
					int ny = y - 1;
					int nz = 1;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'L';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}

				}
			}
			{ // right
				if (y + 1 < m && t[x][y + 1] != '#' && t[x + 1][y + 1] != '#') {
					int nx = x;
					int ny = y + 1;
					int nz = 1;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'R';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
		} else if (z == 2) {
			{ // up
				if (x - 1 >= 0 && t[x - 1][y] != '#' && t[x - 1][y + 1] != '#') {
					int nx = x - 1;
					int ny = y;
					int nz = 2;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'U';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}

				}
			}
			{ // down
				if (x + 1 < n && t[x + 1][y] != '#' && t[x + 1][y + 1] != '#') {
					int nx = x + 1;
					int ny = y;
					int nz = 2;


					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'D';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // left
				if (y - 1 >= 0 && t[x][y - 1] != '#') {
					int nx = x;
					int ny = y - 1;
					int nz = 0;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'L';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
			{ // right
				if (y + 2 < m && t[x][y + 2] != '#') {
					int nx = x;
					int ny = y + 2;
					int nz = 0;

					if (!visited[nx][ny][nz]) {
						mov[nx][ny][nz] =  'R';

						visited[nx][ny][nz] = true;

						px[nx][ny][nz] = x;
						py[nx][ny][nz] = y;
						pz[nx][ny][nz] = z;

						Q[qt++] = nx;
						Q[qt++] = ny;
						Q[qt++] = nz;
					}
				}
			}
		}
	}

	if (!visited[ex][ey][0]) {
		cout << "-1\n";
	} else {
		int x = ex;
		int y = ey;
		int z = 0;

		string answer;

		int steps = 0;

		while (x != sx || y != sy || z != 0) {
			if (!visited[x][y][z]) {
				// assert(false);
				cout << "-1\n";
				return 0;
			} //////
			answer += mov[x][y][z];
			int nx = px[x][y][z];
			int ny = py[x][y][z];
			int nz = pz[x][y][z];
			x = nx;
			y = ny;
			z = nz;
		}

		reverse(answer.begin(), answer.end());

		cout << answer.size() << "\n";
		cout << answer << "\n";
	}

}
