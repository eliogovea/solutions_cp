#include <bits/stdc++.h>

using namespace std;

const int N = 105;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int X, Y, Z;
string m[N][N];
int depth[N][N][N];
queue <int> Q;
int xs, ys, zs;
int xe, ye, ze;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> X >> Y >> Z) {
		if (X == 0 && Y == 0 && Z == 0) {
			break;
		}
		for (int z = 0; z < Z; z++) {
			for (int x = 0; x < X; x++) {
				cin >> m[z][x];
				for (int y = 0; y < Y; y++) {
					if (m[z][x][y] == 'S') {
						xs = x;
						ys = y;
						zs = z;
					}
					if (m[z][x][y] == 'E') {
						xe = x;
						ye = y;
						ze = z;
					}
				}
			}
		}
		//cout << "start: " << xs << " " << ys << " " << zs << "\n";
		//cout << "end: " << xe << " " << ye << " " << ze << "\n";
		for (int x = 0; x < X; x++) {
			for (int y = 0; y < Y; y++) {
				for (int z = 0; z < Z; z++) {
					depth[x][y][z] = -1;
				}
			}
		}
		depth[xs][ys][zs] = 0;
		Q = queue <int>();
		Q.push(xs);
		Q.push(ys);
		Q.push(zs);
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int z = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < X && ny >= 0 && ny < Y) {
					if (m[z][nx][ny] != '#' && depth[nx][ny][z] == -1) {
						depth[nx][ny][z] = depth[x][y][z] + 1;
						Q.push(nx);
						Q.push(ny);
						Q.push(z);
					}
				}
			}
			if (m[z][x][y] == '-') {
				if (z - 1 >= 0 && m[z - 1][x][y] == '-' && depth[x][y][z - 1] == -1) {
					depth[x][y][z - 1] = depth[x][y][z] + 1;
					Q.push(x);
					Q.push(y);
					Q.push(z - 1);
				}
				if (z + 1 < Z && m[z + 1][x][y] == '-' && depth[x][y][z + 1] == -1) {
					depth[x][y][z + 1] = depth[x][y][z] + 1;
					Q.push(x);
					Q.push(y);
					Q.push(z + 1);
				}
			}
			if (depth[xe][ye][ze] != -1) {
				break;
			}
		}
		cout << depth[xe][ye][ze] << "\n";
	}

}
