#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
string s[N];

int grundy[N + 1][N + 1][N + 1][N + 1];
int used[N * N + 100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int lx = 1; lx <= n; lx++) {
		for (int ly = 1; ly <= n; ly++) {
			for (int x1 = 0; x1 + lx - 1 < n; x1++) {
				for (int y1 = 0; y1 + ly - 1 < n; y1++) {
					int x2 = x1 + lx - 1;
					int y2 = y1 + ly - 1;
					int id = N * N * N * x1 + N * N * x2 + N * y1 + y2 + 1;
					for (int px = x1; px <= x2; px++) {
						for (int py = y1; py <= y2; py++) {
							int _grundy = 0;
							if (s[px][py] == '|') {
								if (py != y1) {
									_grundy ^= grundy[x1][y1][x2][py - 1];
								}
								if (py != y2) {
									_grundy ^= grundy[x1][py + 1][x2][y2];
								}
							} else if (s[px][py] == '-') {
								if (px != x1) {
									_grundy ^= grundy[x1][y1][px - 1][y2];
								}
								if (px != x2) {
									_grundy ^= grundy[px + 1][y1][x2][y2];
								}
							} else {
								if (px != x1 && py != y1) {
									_grundy ^= grundy[x1][y1][px - 1][py - 1];
								}
								if (px != x1 && py != y2) {
									_grundy ^= grundy[x1][py + 1][px - 1][y2];
								}
								if (px != x2 && py != y1) {
									_grundy ^= grundy[px + 1][y1][x2][py - 1];
								}
								if (px != x2 && py != y2) {
									_grundy ^= grundy[px + 1][py + 1][x2][y2];
								}
							}
							used[_grundy] = id;
						}
					}
					grundy[x1][y1][x2][y2] = 0;
					while (used[grundy[x1][y1][x2][y2]] == id) {
						grundy[x1][y1][x2][y2]++;
					}
				}
			}
		}
	}
	cout << ((grundy[0][0][n - 1][m - 1] != 0) ? "WIN" : "LOSE") << "\n";
}
