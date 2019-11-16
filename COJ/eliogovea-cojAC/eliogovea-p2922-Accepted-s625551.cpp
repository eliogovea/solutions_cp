#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct pt {
	double x, y;
	pt() {}
	pt(double xx, double yy) : x(xx), y(yy) {}
};

double dist(pt a, pt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

pt a, b, c, d, e, f;

int main() {
	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> e.x >> e.y >> f.x >> f.y) {
		if (a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0 && c.x == 0 && c.y == 0 && d.x == 0 && d.y == 0 && e.x == 0 && e.y == 0 && f.x == 0 && f.y == 0) break;
		double sin_ang = fabs(cross(a, b, c) / (dist(a, b) * dist(a, c)));
		double ah = fabs(cross(d, e, f) / 2.0) / (dist(a, b) * sin_ang);
		double t = ah / (dist(a, c));
		double Hx = a.x + (c.x - a.x) * t;
		double Hy = a.y + (c.y - a.y) * t;
		double Gx = Hx + b.x - a.x;
		double Gy = Hy + b.y - a.y;
		cout.precision(3);
		cout << fixed << Gx << " " << Gy << " " << Hx << " " << Hy << endl;
	}
}
