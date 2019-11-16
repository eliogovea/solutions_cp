#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

typedef pair<int, pair<int, int> > edge;

int n, m, p[MAXN], rank[MAXN], sol, cant;
vector<edge> edges;

inline int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

inline bool join(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return false;
	if (rank[px] > rank[py]) p[py] = px;
	else if (rank[px] < rank[py]) p[px] = py;
	else {
		p[px] = py;
		rank[py]++;
	}
	return true;
}

int main() {
	while (scanf("%d%d", &n, &m) && (n | m)) {
		for (int i = 0; i < n; i++) p[i] = i, rank[i] = 1;
		edges.clear();
		sol = cant = 0;
		for (int i = 0, a, b, c; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edges.push_back(make_pair(c, make_pair(a, b)));
		}
		sort(edges.begin(), edges.end());
		for (vector<edge>::iterator it = edges.begin(); it != edges.end(); it++) {
            if (cant == n - 1) break;
            if (join((it->second).first, (it->second).second))
				sol = max(sol, it->first), cant++;
		}

		if (cant == n - 1) printf("%d\n", sol);
		else printf("IMPOSSIBLE\n");
	}
}
