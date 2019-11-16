#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

struct pt {
	int x, y;
	pt() {}
	pt(int xx, int yy) : x(xx), y(yy) {}
	bool operator < (const pt &P) const {
		if (x != P.x) return x < P.x;
		return y < P.y;
	}
} pts[MAXN];

vector<int> T[MAXN << 2];

void build(int nod, int lo, int hi) {
    T[nod].resize(hi - lo);
	if (lo + 1 == hi) T[nod] = vector<int>(1, pts[lo].y);
	else {
		int mid = (lo + hi) >> 1, L = nod << 1, R = L + 1;
		build(L, lo, mid);
		build(R, mid, hi);
		merge(T[L].begin(), T[L].end(), T[R].begin(), T[R].end(), T[nod].begin());
	}
}

int query(int nod, int lo, int hi, int x, int y) {
	if (pts[lo].x > x) return 0;
	if (pts[hi - 1].x <= x)
		return upper_bound(T[nod].begin(), T[nod].end(), y) - T[nod].begin();
	int mid = (lo + hi) >> 1, L = nod << 1, R = L + 1;
	return query(L, lo, mid, x, y) + query(R, mid, hi, x, y);
}

int tc, n, q, a, b;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			pts[i].x = a + b;
			pts[i].y = b - a;
		}
		sort(pts, pts + n);
		build(1, 0, n);
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &a, &b);
			printf("%d\n", query(1, 0, n, a + b, b - a));
		}
	}
}
