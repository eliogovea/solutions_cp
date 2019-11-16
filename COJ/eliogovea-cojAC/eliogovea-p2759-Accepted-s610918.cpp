#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2010;

int n, c;
int p[MAXN], rank[MAXN];

void make(int x) {
	p[x] = x; rank[x] = 1;
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

bool join(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return 0;
	if (rank[px] > rank[py]) p[py] = px;
	else if (rank[py] > rank[px]) p[px] = py;
	else {
		p[px] = py;
		rank[py]++;
	}
	return 1;
}

vector<pair<int, pair<int, int> > > edges;

int x[MAXN], y[MAXN];

int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		make(i);
		scanf("%d%d", &x[i], &y[i]);
		for (int j = 0; j < i; j++) {
			int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (d >= c)edges.push_back(make_pair(d, make_pair(i, j)));
		}
	}

	int sol = 0, ce = 0;

	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
		if (join(edges[i].second.first, edges[i].second.second)) {
			sol += edges[i].first;
			ce++;
		}
	if (ce == n - 1) printf("%d\n", sol);
	else printf("-1\n");
}
