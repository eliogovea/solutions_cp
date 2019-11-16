#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 300010;

vector<pair<int, int> > v;

int p[MAXN], rank[MAXN];

void make(int x) {
	p[x] = x;
	rank[x] = 1;
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int join(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return 1;
	if (rank[px] > rank[py]) p[py] = px;
	else if (rank[px] < rank[py]) p[px] = py;
	else {
		p[px] = py;
		rank[py]++;
	}
	return 0;
}

int id, n;
map<int, int> m;
int pts[2 * MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0, x, r; i < n; i++) {
		scanf("%d%d", &x, &r);
		v.push_back(make_pair(r, x));
	}

	sort(v.begin(), v.end());
	int sol = 1;
	for (int i = 0; i < n; i++) {
		sol++; int a, b;
		if (m.find(v[i].second - v[i].first) == m.end()) {
			make(id);
			a = m[v[i].second - v[i].first] = id++;
		}
		else a = m[v[i].second - v[i].first];
		if (m.find(v[i].second + v[i].first) == m.end()) {
			make(id);
			b = m[v[i].second + v[i].first] = id++;
		}
		else b = m[v[i].second + v[i].first];
		sol += join(a, b);
	}
	printf("%d\n", sol);
}
