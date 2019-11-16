//============================================================================
// Name        : 2571.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 405;

int p[N];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	if (rand() & 1) p[x] = y;
	else p[y] = x;
	return true;
}

int n, x[N], y[N], q, mx[N][N];
vector<int> G[N], D[N];

inline int dist(int i, int j) {
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	return dx * dx + dy * dy;
}

struct edge {
	int a, b, c;
} e;

bool operator < (const edge &a, const edge &b) {
	return a.c < b.c;
}

vector<edge> E;

void dfs(int r, int u, int par, int m) {
	mx[r][u] = m;
	for (int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		int d = D[u][i];
		if (v == par) continue;
		dfs(r, v, u, (m < d) ? d : m);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		scanf("%d%d", x + i, y + i);
		for (int j = 1; j < i; j++) {
			e.a = i;
			e.b = j;
			e.c = dist(i, j);
			E.push_back(e);
		}
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < (int)E.size(); i++)
		if (join(E[i].a, E[i].b)) {
			G[E[i].a].push_back(E[i].b);
			D[E[i].a].push_back(E[i].c);
			G[E[i].b].push_back(E[i].a);
			D[E[i].b].push_back(E[i].c);
		}
	for (int i = 1; i <= n; i++) dfs(i, i, 0, 0);
	for (int a, b; q--;) {
		scanf("%d%d", &a, &b);
		double ans = mx[a][b];
		ans = sqrt(ans);
		printf("%.2lf\n", ans);
	}
}
