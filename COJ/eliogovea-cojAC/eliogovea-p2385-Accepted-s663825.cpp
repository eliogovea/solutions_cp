//============================================================================
// Name        : 2385.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 505;

int tc, n, x[MAXN], y[MAXN], ans;

inline int dist(int i, int j) {
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	return dx * dx + dy * dy;
}

struct edge {
	int a, b, c;
	edge(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {};
	bool operator < (const edge &E) const {
		return c < E.c;
	}
};

vector<edge> E;
vector<edge>::iterator it;

int p[MAXN], rank[MAXN];

void make(int x) {
	p[x] = x;
	rank[x] = 1;
}

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

bool join(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return false;
	if (rank[px] > rank[py]) p[py] = px;
	else if (rank[py] > rank[px]) p[px] = py;
	else {
		rank[py]++;
		p[px] = py;
	}
	return true;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		E.clear();
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			make(i);
			for (int j = 0; j < i; j++)
				E.push_back(edge(i, j, dist(i, j)));

		}
		sort(E.begin(), E.end());
		int cnt = 0;
		for (it = E.begin(); it != E.end() && cnt < n - 1; it++)
			if (join(it->a, it->b)) ans = it->c, cnt++;
		printf("%.3lf\n", sqrt(ans));
	}
}
