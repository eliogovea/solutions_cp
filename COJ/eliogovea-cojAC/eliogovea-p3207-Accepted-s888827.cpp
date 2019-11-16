#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

const long double EPS = 1e-7;

int n;
double x[N], y[N];

struct item {
	int id;
	long double r1, r2;
};

bool cmp_r1(item a, item b) {
	return a.r1 < a.r2;
}

bool cmp_r2(item a, item b) {
	return a.r2 < b.r2;
}

item a[N];

set <pair <int, int> > edges;

int ID1[N], ID2[N];

vector <int> g[N];
int L, R;
int match[N];
int used[N];
int ttt;

bool dfs(int u) {
	if (used[u] == ttt) {
        return false;
	}
	used[u] = ttt;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int p[2][N];

int find(int id, int x) {
	if (p[id][x] != x) {
		p[id][x] = find(id, p[id][x]);
	}
	return p[id][x];
}

bool join(int id, int x, int y) {
	x = find(id, x);
	y = find(id, y);
	if (rand() & 1) {
		p[id][x] = y;
	} else {
		p[id][y] = x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		p[0][i] = p[1][i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		a[i].id = i;
		a[i].r1 = (x[i] * x[i] + y[i] * y[i]) / (2.0 * x[i]);
		a[i].r2 = (x[i] * x[i] + y[i] * y[i]) / (2.0 * y[i]);
		for (int j = 0; j < i; j++) {
			if (fabs(a[j].r1 - a[i].r1) < EPS) {
				join(0, i, j);
			}
			if (fabs(a[j].r2 - a[i].r2) < EPS) {
				join(1, i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int x = find(0, i);
		int y = find(1, i);
		//cout << i << " " << x << " " << y << "\n";
		if (edges.find(make_pair(x, y)) == edges.end()) {
			edges.insert(make_pair(x, y));
			g[x].push_back(y);
		}
	}
	for (int i = 0; i < n; i++) {
        match[i] = -1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
        if (find(0, i) != i) continue;
		ttt++;
		if (dfs(i)) ans++;
	}
	cout << ans << "\n";
}
