#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int M = 20005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int r, c;
string s[55];

bool mark[55][55];

vector <int> g[N];

int mt[N];
int used[N], id;

bool match(int u) {
	if (used[u] == id) {
		return false;
	}
	used[u] = id;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (mt[v] == -1 || match(mt[v])) {
			mt[v] = u;
			return true;
		}
	}
	return false;
}

void dfs(int x, int y, vector <pair <int, int> > & v) {
    v.push_back(make_pair(x, y));
    mark[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < r && yy >= 0 && yy < c) {
            if (s[xx][yy] != 'X' && !mark[xx][yy]) {
                dfs(xx, yy, v);
            }
        }
    }
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("dat.txt", "r", stdin);

    while (cin >> r >> c) {
        int ans = 2;
        for (int i = 0; i < r; i++) {
            cin >> s[i];
            for (int j = 0; j < c; j++) {
                mark[i][j] = false;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (ans == 1) {
                    continue;
                }
                if (s[i][j] != 'X' && !mark[i][j]) {
                    vector <pair <int, int> > v;
                    dfs(i, j, v);
                    sort(v.begin(), v.end());
                    for (int i = 0; i < v.size(); i++) {
                        g[i].clear();
                        mt[i] = -1;
                    }

                    int w = 0;
                    int b = 0;
                    for (int i = 0; i < v.size(); i++) {
                         if ((v[i].first & 1) ^ (v[i].second & 1) != 0) {
                            w++;
                            continue;
                        }
                        b++;
                    }

                    if (w != b) {
                        ans = 1;
                        break;
                    }

                    for (int i = 0; i < v.size(); i++) {
                        for (int j = 0; j < 4; j++) {
                            int xx = v[i].first + dx[j];
                            int yy = v[i].second + dy[j];
                            if (xx >= 0 && xx < r && yy >= 0 && yy < c) {
                                if (s[xx][yy] == 'X') {
                                    continue;
                                }
                                int p = lower_bound(v.begin(), v.end(), make_pair(xx, yy)) - v.begin();
                                g[i].push_back(p);
                            }
                        }
                    }
                    bool ok = true;
                    for (int i = 0; i < v.size(); i++) {
                        if ((v[i].first & 1) ^ (v[i].second & 1) != 0) {
                            continue;
                        }
                        id++;
                        if (!match(i)) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        ans = 1;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

}
