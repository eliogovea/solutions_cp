#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <bitset>
#include <queue>
#include <set>
#include <map>

using namespace std;

const double eps = 1e-7;

int tc, n, m;
double x[105], y[105], xx[105], yy[105], s, v;

inline double dist(int i, int j) {
	double dx = x[i] - xx[j];
	double dy = y[i] - yy[j];
	return sqrt(dx * dx + dy * dy);
}

vector<int> G[105];
int mark[105], id, match[105];

bool kuhn(int u) {
	if (mark[u] == id) return false;
	mark[u] = id;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (match[v] == -1 || kuhn(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int matching() {
	int ret = 0;
	for (int i = 0; i <= 100; i++) match[i] = -1;
	for (int i = 0; i < n; i++) {
		id++;
		if (kuhn(i)) ret++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> s >> v) {
		for (int i = 0; i < n; i++) {
			G[i].clear();
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < m; i++)
			cin >> xx[i] >> yy[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				double d = dist(i, j) / v;
				if (d <= s + eps) G[i].push_back(j);
			}
		int cnt = n - matching();
		cout << cnt << "\n";
	}
}
