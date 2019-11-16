#include <bits/stdc++.h>

using namespace std;

const int N = 805;

int n, m;
string mat[N];

int used[N * N];
int match[N * N];
int nh, nv;
vector <int> xh, yh, lh;
vector <int> xv, yv, lv;

int matchH[N * N];
int matchV[N * N];

int id;

vector <int> graph[N * N];

vector <int> graphV[N * N];

bool dfs(int u) {
	if (used[u] == id) {
		return false;
	}
	used[u] = id;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (matchH[v] == -1 || dfs(matchH[v])) {
			matchH[v] = u;
			return true;
		}
	}
	return false;
}

bool markH[N * N];
bool markV[N * N];

bool possibleH[N * N];
bool possibleV[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
		}
		xh.clear();
		yh.clear();
		lh.clear();
		for (int r = 0; r < n; r++) {
			for (int c = 0, last = 0; c <= m; c++) {
				if (c == m || mat[r][c] == '.') {
					if (mat[r][last] == '*') {
						xh.push_back(r);
						yh.push_back(last);
						lh.push_back(c - last);
					}
					last = c;
				} else {
					if (mat[r][last] == '.') {
						last = c;
					}
				}
			}
		}
		xv.clear();
		yv.clear();
		lv.clear();
		for (int c = 0; c < m; c++) {
			for (int r = 0, last = 0; r <= n; r++) {
				if (r == n || mat[r][c] == '.') {
					if (mat[last][c] == '*') {
						xv.push_back(last);
						yv.push_back(c);
						lv.push_back(r - last);
					}
					last = r;
				} else {
					if (mat[last][c] == '.') {
						last = r;
					}
				}
			}
		}

		nh = xh.size();
		nv = xv.size();

		for (int i = 0; i < nh; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < nv; i++) {
			graphV[i].clear();
		}

		for (int i = 0; i < nh; i++) {
			for (int j = 0; j < nv; j++) {
				if (xv[j] <= xh[i] && xh[i] <= xv[j] + lv[j] - 1 && yh[i] <= yv[j] && yv[j] <= yh[i] + lh[i] - 1) {
					graph[i].push_back(j);
					graphV[j].push_back(i);
				}
			}
			matchV[i] = -1;
		}
		for (int i = 0; i < nv; i++) {
			matchH[i] = -1;
		}
		int maxMatch = 0;
		for (int i = 0; i < nh; i++) {
			id++;
			if (dfs(i)) {
				maxMatch++;
			}
		}
		for (int i = 0; i < nh; i++) {
			matchV[i] = -1;
		}
		for (int i = 0; i < nv; i++) {
			if (matchH[i] != -1) {
				matchV[matchH[i]] = i;
			}
		}
		for (int i = 0; i < nh; i++) {
			markH[i] = false;
			possibleH[i] = false;
		}
		for (int i = 0; i < nv; i++) {
			markV[i] = false;
			possibleV[i] = false;
		}

		for (int h = 0; h < nh; h++) {
			if (matchV[h] != -1) {
				possibleH[h] = true;
				possibleV[matchV[h]] = true;
			}
		}

		while (true) {
			bool change = false;
			for (int h = 0; h < nh; h++) {
				if (matchV[h] == -1 || possibleH[h] == false) {
					for (int i = 0; i < graph[h].size(); i++) {
						int v = graph[h][i];
						assert(matchH[v] != -1);
						if (possibleH[matchH[v]]) {
							possibleH[matchH[v]] = false;
							change = true;
						}
					}
				}
			}
			for (int v = 0; v < nv; v++) {
				if (matchH[v] == -1 || possibleV[v] == false) {
					for (int i = 0; i < graphV[v].size(); i++) {
						int h = graphV[v][i];
						assert(matchV[h] != -1);
						if (possibleV[matchV[h]]) {
							possibleV[matchV[h]] = false;
							change = true;
						}
					}
				}
			}
			if (!change) {
				break;
			}
		}
        /*
		cout << "H:\n";
		for (int i = 0; i < nh; i++) {
            cout << i << " " << xh[i] << " " << yh[i] << " " << lh[i] << "\n";
		}
		cout << "\n";

		cout << "V:\n";
		for (int i = 0; i < nv; i++) {
            cout << i << " " << xv[i] << " " << yv[i] << " " << lv[i] << "\n";
		}
		cout << "\n";

		cout << "Edges:\n";
		for (int h = 0; h < nh; h++) {
            for (int i = 0; i < graph[h].size(); i++) {
                int v = graph[h][i];
                cout << h << " " << v << "\n";
            }
		}
		cout << "\n";

		cout << "Match:\n";
		for (int i = 0; i < nh; i++) {
            if (matchV[i] != -1) {
                cout << i << " " << matchV[i] << "\n";
            }
		}
		cout << "\n";

		*/

		cout << maxMatch << "\n";

		int count = 0;

		for (int h = 0; h < nh; h++) {
			if (possibleH[h]) {
                possibleV[matchV[h]] = false;
				cout << "hline " << xh[h] + 1 << " " << yh[h] + 1 << " " << yh[h] + lh[h] - 1 + 1 << "\n";
				count++;
			}
		}

		for (int v = 0; v < nv; v++) {
			if (possibleV[v]) {
				cout << "vline " << yv[v] + 1 << " " << xv[v] + 1 << " " << xv[v] + lv[v] - 1 + 1 << "\n";
				count++;
			}
		}

		assert(count == maxMatch);
	}
}