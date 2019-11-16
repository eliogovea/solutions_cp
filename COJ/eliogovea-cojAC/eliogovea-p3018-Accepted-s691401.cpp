//============================================================================
// Name        : 3018.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int tc, r, c, bx, by, ex, ey, dist[35][35];
string m[35];
queue<int> Qx, Qy;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			cin >> m[i];
			for (int j = 0; j < c; j++) {
				if (m[i][j] == 'b') bx = i, by = j;
				if (m[i][j] == 'g') ex = i, ey = j;
			}
		}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				dist[i][j] = -1;
		dist[bx][by] = 0;
		Qx.push(bx);
		Qy.push(by);
		while (!Qx.empty()) {
			int x = Qx.front(); Qx.pop();
			int y = Qy.front(); Qy.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (m[nx][ny] != '.' && m[nx][ny] != 'g') continue;
				if (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					Qx.push(nx);
					Qy.push(ny);
				}
			}
		}
		if (dist[ex][ey] != -1) cout << "Good\n";
		else cout << "Bad\n";
	}
}

