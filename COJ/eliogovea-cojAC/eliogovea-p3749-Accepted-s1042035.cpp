#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
string s[25];
int id[25][1005];
vector <int> G[25005];
int visited[25005];
int timer;
int match[25005];

bool dfs(int u) {
	if (visited[u] == timer) {
		return false;
	}
	visited[u] = timer;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cas = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int w = 0;
		int b = 0;
		int t = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++) {
				if (s[i][j] != '#') {
					t++;
					if ((i & 1) == (j & 1)) {
						id[i][j] = w++;
					} else {
						id[i][j] = b++;
					}
				}
			}
		}
		for (int i = 0; i < w; i++) {
			G[i].clear();
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (s[x][y] != '#') {
					if ((x & 1) == (y & 1)) {
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
								if (s[nx][ny] != '#') {
									G[id[x][y]].push_back(id[nx][ny]);
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < b; i++) {
			match[i] = -1;
		}
		int ans = 0;
		for (int i = 0; i < w; i++) {
			timer++;
			if (dfs(i)) {
				ans++;
			}
		}
		cout << "Case #" << cas++ << ": " << (t - 2 * ans + 1) / 2 << "\n";
	}
}
