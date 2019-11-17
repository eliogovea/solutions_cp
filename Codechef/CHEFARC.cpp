#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t;
int n, m, k1, k2;
int tab[N][N];
int dist1[N][N];
int dist2[N][N];
bool visited[N][N];
queue <pair <int, int> > Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k1 >> k2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tab[i][j];
			}
		}
		if (m == 1) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dist1[i][j] = dist2[i][j] = -1;
			}
		}
		dist1[0][0] = 0;
		Q.push(make_pair(0, 0));
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int dx = -k1; dx <= k1; dx++) {
				for (int dy = -(k1 - abs(dx)); dy <= (k1 - abs(dx)); dy++) {
					if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m) {
						if (tab[x + dx][y + dy] == 0 && dist1[x + dx][y + dy] == -1) {
							dist1[x + dx][y + dy] = dist1[x][y] + 1;
							Q.push(make_pair(x + dx, y + dy));
						}
					}
				}
			}
		}
		dist2[0][m - 1] = 0;
		Q.push(make_pair(0, m - 1));
		while (!Q.empty()) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int dx = -k2; dx <= k2; dx++) {
				for (int dy = -(k2 - abs(dx)); dy <= (k2 - abs(dx)); dy++) {
					if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m) {
						if (tab[x + dx][y + dy] == 0 && dist2[x + dx][y + dy] == -1) {
							dist2[x + dx][y + dy] = dist2[x][y] + 1;
							Q.push(make_pair(x + dx, y + dy));
						}
					}
				}
			}
		}

		int ans = -1;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (dist1[x][y] != -1 && dist2[x][y] != -1) {
                    int tmp = max(dist1[x][y], dist2[x][y]);
                    if (ans == -1 || ans > tmp) {
                        ans = tmp;
                    }
				}
			}
		}
		cout << ans << "\n";
	}
}

