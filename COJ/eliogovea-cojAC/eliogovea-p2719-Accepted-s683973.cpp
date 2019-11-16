#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-7;
const int MAXN = 100005;

struct pt {
	double x, y;
	pt() {}
	pt(double xx, double yy) : x(xx), y(yy) {}
	bool operator < (const pt &P) const {
		if (x != P.x) return x < P.x;
		return y < P.y;
	}
} P[MAXN], CH[MAXN];

int Ps, CHs;

double cross(const pt &a, const pt &b, const pt &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cw(const pt &a, const pt &b, const pt &c) {
	return cross(a, b, c) < 0.0;
}

double dist(const pt &a, const pt &b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

bool cmp(const pt &a, const pt &b) {
	double cr = cross(P[0], a, b);
	if (fabs(cr) < eps) return dist(P[0], a) < dist(P[0], b);
	return cr < 0.0;
}

void ConvexHull() {
	pt aux;
	for (int i = 0; i < Ps; i++)
		if (P[i] < P[0]) {
			aux = P[i];
			P[i] = P[0];
			P[0] = aux;
		}
	sort(P + 1, P + Ps, cmp);
	int k = 0;
	for (int i = 0; i < Ps; i++) {
		while (k >= 2 && !cw(CH[k - 2], CH[k - 1], P[i])) k--;
		CH[k++] = P[i];
	}
	CHs = k;
}

double max_dist() {
	double mx = 0;
	ConvexHull();
	for (int i = 0, j = 0; i < CHs; i++) {
		while (dist(CH[i], CH[(j + 1) % CHs]) > dist(CH[i], CH[j]))
			j = (j + 1) % CHs;
		double d = dist(CH[i], CH[j]);
		if (mx < d) mx = d;
	}
	return mx;
}


int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	Ps = a + b;
    for (int i = 0; i < Ps; i++)
        scanf("%lf%lf", &P[i].x, &P[i].y);
    printf("%.4lf\n", max_dist());
}
