#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

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

double r;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> Ps >> r;
    for (int i = 0; i < Ps; i++)
    cin >> P[i].x >> P[i].y;
    ConvexHull();
	double per = 0.0;
	for (int i = 0, j = CHs - 1; i < CHs; j = i++) {
		per += dist(CH[i], CH[j]);
	}
	double area = 0.0;
	for (int i = 1; i + 1 < CHs; i++) {
		area += -cross(CH[0], CH[i], CH[i + 1]);
	}
	area /= 2.0;
    cout.precision(2);
	cout << fixed << area << " " << fixed << per * r << "\n";
}
