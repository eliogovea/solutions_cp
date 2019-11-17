#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

inline int sign(double x) {
	if (x > EPS) {
		return 1;
	}
	if (x < -EPS) {
		return -1;
	}
	return 0;
}

struct pt {
	double x, y;
	pt() {}
	pt(double _x, double _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

double cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

struct rect {
	double a, b, c;
	rect() {}
	rect(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
	rect(pt p1, pt p2) {
		double dx = p2.x - p1.x;
		double dy = p2.y - p1.y;
		a = dy;
		b = -dx;
		c = a * p1.x + b * p1.y;
	}
};

inline bool intersect(rect a, rect b, pt &P) {
	double D = a.a * b.b - a.b * b.a;
	if (abs(D) < EPS) {
		return false;
	}
	double D1 = a.c * b.b - a.b * b.c;
	double D2 = a.a * b.c - a.c * b.a;
	P.x = D1 / D;
	P.y = D2 / D;
	return true;
}

inline bool isIn(double l, double r, double x) {
    if (l > r) {
        swap(l, r);
    }
	return (l - EPS <= x && x <= r + EPS);
}

inline bool contains(pt a, pt b, pt p) {
	return (isIn(a.x, b.x, p.x) && isIn(a.y, b.y, p.y));
}

inline bool intersect(pt a, pt b, pt c, pt d) {
	rect rab = rect(a, b);
	rect rcd = rect(c, d);
	pt P;
	if (!intersect(rab, rcd, P)) {
		return false;
	}
	return (contains(a, b, P) && contains(c, d, P));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    //cerr.precision(5);
	//freopen("dat.txt", "r", stdin);
	int t;
	vector <pt> pts(7);
	double p;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 7; i++) {
			cin >> pts[i].x >> pts[i].y;
		}
		cin >> p;
		vector <int> v(7);
		for (int i = 0; i < 7; i++) {
			v[i] = i;
		}
		bool ans = false;
		do {
			bool ok = true;
			for (int i = 1; i < 6 && ok; i++) {
				for (int j = i + 2; j < 7 && ok; j++) {
					if (intersect(pts[v[i]], pts[v[i + 1]], pts[v[j]], pts[v[j == 6 ? 0 : j + 1]])) {
						ok = false;
					}
				}
			}
			for (int i = 1; i <= 4 && ok; i++) {
                if (intersect(pts[v[i]], pts[v[i + 1]], pts[v[0]], pts[v[6]])) {
                    ok = false;
                }
			}
			for (int i = 2; i <= 5 && ok; i++) {
                if (intersect(pts[v[i]], pts[v[i + 1]], pts[v[0]], pts[v[1]])) {
                    ok = false;
                }
			}
			if (!ok) {
				continue;
			}
			double area = 0.0;
			for (int i = 1; i < 6; i++) {
				area += cross(pts[v[i]] - pts[v[0]], pts[v[i + 1]] - pts[v[0]]);
			}
			area = abs(area);
			area /= 2.0;
			area = area * area * area;
			if (abs(area / (4.0 * 4.0 * 4.0) - p) < 1e-5 + EPS) {
                //cerr << fixed << abs(area / (4.0 * 4.0 * 4.0) - p) << "\n";
				ans = true;
				break;
			}
		} while (next_permutation(v.begin(), v.end()));
		assert(ans);
		//cerr << (ans ? "OK" : "WRONG") << "\n";
		for (int i = 0; i < 7; i++) {
			cout << v[i] + 1;
			if (i < 6) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
