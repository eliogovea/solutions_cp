#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct pt {
	double x, y;
	pt() {}
	pt(double xx, double yy) : x(xx), y(yy) {}
	bool operator < (const pt &P) const {
		if (x != P.x) return x < P.x;
		return y < P.y;
	}
};

pt pts[MAXN];

vector<double> T[MAXN << 2];

void build(int nod, int lo, int hi) {
	T[nod].resize(hi - lo);
	if (lo + 1 == hi) T[nod][0] = pts[lo].y;
	else {
		int mid = (lo + hi) >> 1, L = nod << 1, R = L + 1;
		build(L, lo, mid);
		build(R, mid, hi);
		merge(T[L].begin(), T[L].end(),
            T[R].begin(), T[R].end(),
            T[nod].begin());
	}
}

int query(int nod, int lo, int hi, double x, double y) {
	if (pts[lo].x > x) return 0;
	if (pts[hi - 1].x <= x)
		return upper_bound(T[nod].begin(), T[nod].end(), y) - T[nod].begin();
	int mid = (lo + hi) >> 1, L = nod << 1, R = L + 1;
	return query(L, lo, mid, x, y) + query(R, mid, hi, x, y);
}

double dist(pt &a, pt &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n, q, cas;
pt ca, cb, aux;
double X, Y;

int main() {
	while (scanf("%d", &n) && n) {
		printf("Case %d:\n", ++cas);
		for (int i = 0; i < n; i++) scanf("%lf%lf", &pts[i].x, &pts[i].y);
		scanf("%lf%lf%lf%lf%d", &ca.x, &ca.y, &cb.x, &cb.y, &q);
		for (int i = 0; i < n; i++) {
			aux = pts[i];
			pts[i].x = dist(aux, ca);
			pts[i].y = dist(aux, cb);
		}
		sort(pts, pts + n);
		build(1, 0, n);
		while (q--) {
			scanf("%lf%lf", &X, &Y);
			int com = query(1, 0, n, X, Y),
                p1 = query(1, 0, n, X, 1e10),
                p2 = query(1, 0, n, 1e10, Y),
                out = n - p1 - p2 + com;
			if (out <= com) printf("0\n");
			else printf("%d\n", out - com);
		}
	}
}
