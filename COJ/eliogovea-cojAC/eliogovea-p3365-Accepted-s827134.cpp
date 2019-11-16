#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define sqr(x) ((x) * (x))

const long double eps = (long double)1e-9;

const long double pi = acos(-1.0);

struct point {
	long double x, y;
};

int n;
vector <point> p, hull;
long double ans;

bool cmp(point a, point b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool eq(point a, point b) {
	return (a.x == b.x && a.y == b.y);
}

bool isCCW(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void setConvexHull(vector <point> p, vector <point> &h) {
	sort(p.begin(), p.end(), cmp);
	p.erase(unique(p.begin(), p.end(), eq), p.end());

	vector <point> up, down;
	point head = p[0], tail = p.back();

	up.push_back(head); down.push_back(head);

	for (int i = 1; i < (int) p.size(); i++) {
		if (i == (int) p.size() - 1 || !isCCW(tail, head, p[i])) {
			while ( (int) up.size() >= 2 && isCCW(up[up.size() - 2], up.back(), p[i]) )
				up.pop_back();
			up.push_back(p[i]);
		}
		if (i == (int) p.size() - 1 || isCCW(tail, head, p[i])) {
			while ( (int) down.size() >= 2 && !isCCW(down[down.size() - 2], down.back(), p[i]) )
				down.pop_back();
			down.push_back(p[i]);
		}
	}

	h.clear();
	for (int i = 0; i < (int) up.size(); i++)
		h.push_back(up[i]);
	for (int i = (int) down.size() - 2; i > 0; i--)
		h.push_back(down[i]);

}

long double dist2(point a, point b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

long double dist(point a, point b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double cross(const point &a, const point &b, const point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long double dot(const point &a, const point &b, const point &c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		long long x, y;
		cin >> x >> y;
		point tmp;
		tmp.x = x;
		tmp.y = y;
		p.push_back(tmp);
	}

	setConvexHull(p, hull);

	for (int i = 0; i < hull.size(); i++) {
		int prev = (i == 0) ? hull.size() - 1 : i - 1;
		int cur = i;
		int next = (i == hull.size() - 1) ? 0 : i + 1;
        long double a = sqrt(dist2(hull[cur], hull[prev]) * dist2(hull[cur], hull[next]));
		long double c = cross(hull[cur], hull[prev], hull[next]);
		long double d = dot(hull[cur], hull[prev], hull[next]);
		long double ang = asin((long double) c / a) * (long double)180.0 / pi;
		if (d < -eps) {
            ang = ((long double) 180.0) - ang;
		}
		if ((i == 0) || (ang < ans)) {
			ans = ang;
		}
	}

	printf("%.6lf\n", (double)ans);

	return 0;
}
