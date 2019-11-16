#include <bits/stdc++.h>

using namespace std;

const int N = 505;

typedef double LD;

const LD EPS = 1e-13;

const LD PI = M_PI;

struct pt {
	LD x, y;
	pt() {}
	pt(LD _x, LD _y) {
		x = _x;
		y = _y;
	}
};

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline LD dist(pt a, pt b) {
	LD dx = a.x - b.x;
	LD dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

struct circle {
	pt O;
	LD r;
	circle() {}
	circle(pt _O, LD _r) {
		O = _O;
		r = _r;
	}
};

int inter(circle a, circle b, pt &P1, pt &P2) {
	LD d = dist(a.O, b.O);
	LD dx = b.O.x - a.O.x;
	LD dy = b.O.y - a.O.y;
	if (fabs(dist(a.O, b.O) - a.r - b.r) < EPS) {
		LD xx = a.O.x + dx / 2.0;
		LD yy = a.O.y + dy / 2.0;
		P1.x = a.O.x + dx / 2.0;
		P1.y = a.O.y + dy / 2.0;
		return 1;
	} else if (d < a.r + b.r) {
		LD xx = a.O.x + dx / 2.0;
		LD yy = a.O.y + dy / 2.0;
		LD l = sqrt(a.r * a.r - d * d / 4.0);
		LD ndx = -dy;
		LD ndy = dx;
		LD t = l / d;
		P1.x = xx - ndx * t;
		P1.y = yy - ndy * t;
		P2.x = xx + ndx * t;
		P2.y = yy + ndy * t;
		return 2;
	}
	return 0;
}

LD get_angle(pt P) {
	LD x = P.x;
	LD y = P.y;
	if (fabs(x) < EPS) {
		if (y > 0.0) {
			return PI / 2.0;
		} else {
			return 3.0 * PI / 2.0;
		}
	}
	LD angle = atan(fabs(y / x));
	if (x > 0.0) {
		if (y > 0.0) {
			return angle;
		} else {
			return 2.0 * PI - angle;
		}
	} else {
		if (y > 0) {
			return PI - angle;
		} else {
			return PI + angle;
		}
	}
}

int n, p;
pt pts[505];

bool cmp(const pair <LD, bool> &a, const pair <LD, bool> &b) {
	if (fabs(a.first - b.first) > EPS) {
		return a.first < b.first;
	}
	return !a.first;
}

pair <LD, bool> events[2 * N];
int sze;

bool check(LD r) {
	for (int i = 0; i < n; i++) {
		sze = 0;
		int cur = 0;
		int mx = 0;
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			pt P1, P2;
			int c = inter(circle(pt(0, 0), r), circle(pts[j] - pts[i], r), P1, P2);
			if (c == 1) {
				LD angle = get_angle(P1);
				events[sze].first = angle;
				events[sze++].second = false;
				events[sze].first = angle;
				events[sze++].second = true;
			} else if (c == 2) {
				LD angle1 = get_angle(P1);
				LD angle2 = get_angle(P2);
				if (angle1 > angle2) {
					cur++;
				}
				events[sze].first = angle1;
				events[sze++].second = false;
				events[sze].first = angle2;
				events[sze++].second = true;
			}
		}
		if (cur + 1 >= p) {
			return true;
		}
		sort(events, events + sze, cmp);
		for (int i = 0; i < sze; i++) {
			if (!events[i].second) {
				cur++;
			} else {
				cur--;
			}
			if (cur + 1 >= p) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(4);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> p) {
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}


		if (p == 1) {
			cout << "0.0000\n";
			continue;
		}
		LD lo = 0.0;
		LD hi = 1e5 * sqrt(2.0) / 2.0 + 20.0;

		for (int it = 0; it < 100; it++) {
			double mid = (lo + hi) / 2.0;
			if (check(mid)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}

		double ans = (lo + hi) / 2.0;

		cout << fixed << ans << "\n";
	}
}
