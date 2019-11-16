#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

struct pt {
	double x, y;
	pt() {}
	pt(double a, double b) : x(a), y(b) {}
} p1, p2;

struct line {
	double a, b, c;
	line() {}
	line(pt p1, pt p2) {
		if (p1.x == p2.x) {
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}
		else if (p1.y == p2.y) {
			a = 0.0;
			b = 1.0;
			c = -p1.y;
		}
		else {

		    double dx = p1.x - p2.x;
		    double dy = p1.y - p2.y;

		    a = -dy;
		    b = dx;
		    c = -dx * p1.y + dy * p1.x;
		}
	}
} l1, l2;


const double c = 100.0;

line form(int x, int y, int a) {
	line l;
	if (a == 0 || a == 180) {
		l.a = 1.0; l.b = 0.0; l.c = -x;
	}
	else if (a == 90 || a == 270) {
		l.a = 0.0; l.b = 1.0; l.c = -y;
	}
	else if (a > 0 && a < 90) {
		l = line(pt(x, y), pt(x + c * tan(M_PI * double(a) / 180.0), y + c));
	}
	else if (a > 90 && a < 180) {
		a = 180 - a;
		l = line(pt(x, y), pt(x + c * tan(M_PI * double(a) / 180.0), y - c));
	}
	else if (a > 180 && a < 270) {
		a  -= 180;
		l = line(pt(x, y), pt(x - c * tan(M_PI * double(a) / 180.0), y - c));
	}
	else {
		a = 360 - a;
		l = line(pt(x, y), pt(x - c * tan(M_PI * double(a) / 180.0), y + c));
	}
	return l;
}

pt intersect(line l1, line l2) {
	pt p;
	p.x = (-l1.c * l2.b + l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
	p.y = (-l2.c * l1.a + l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
	return p;
}

int tc, a1, a2;

int main() { //freopen("dat.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> p1.x >> p1.y >> a1 >> p2.x >> p2.y >> a2;
		l1 = form(p1.x, p1.y, a1);
		l2 = form(p2.x, p2.y, a2);
		pt p = intersect(l1, l2);
		cout.precision(4);
		cout << fixed << p.x << " " << p.y << "\n";
	}
}
