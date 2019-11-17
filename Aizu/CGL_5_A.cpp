/*
	Geometry Template
	double !!!
	TODO: test everything!!!
*/

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e17;
const double EPS = 1e-9;
const double PI = 2.0 * asin(1);

inline bool is_in(double a, double b, double x) {
	if (a > b) {
		swap(a, b);
	}
	return (a - EPS <= x && x <= b + EPS);
}

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

bool operator < (const point &P, const point &Q) {
	if (abs(P.y - Q.y) > EPS) {
		return P.y < Q.y;
	}
	if (abs(P.x - Q.x) > EPS) {
		return P.x < Q.x;
	}
	return false;
}

struct compare_by_x {
	bool operator () (const point &P, const point &Q) {
		if (abs(P.x - Q.x) > EPS) {
			return P.x < Q.x;
		}
		return P.y < Q.y;
	}
};

struct compare_by_y {
	bool operator () (const point &P, const point &Q) {
		if (abs(P.y - Q.y) > EPS) {
			return P.y < Q.y;
		}
		return P.x < Q.x;
	}
};
inline void read(point &P) {
	cin >> P.x >> P.y;
}

point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point &P, const double k) {
	return point(P.x * k, P.y * k);
}

point operator / (const point &P, const double k) {
	assert(fabs(k) > EPS);
	return point(P.x / k, P.y / k);
}

inline double dot(const point &P, const point &Q) {
	return P.x * Q.x + P.y * Q.y;
}

inline double cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline double norm2(const point &P) {
	return dot(P, P);
}

inline double norm(const point &P) {
	return sqrt(dot(P, P));
}

inline double dist2(const point &P, const point &Q) {
	return norm2(P - Q);
}

inline double dist(const point &P, const point &Q) {
	return sqrt(dot(P - Q, P - Q));
}

inline bool is_in(point A, point B, point P) {
	if (abs(cross(B - A, P - A)) > EPS) {
		return false;
	}
	return (is_in(A.x, B.x, P.x) && is_in(A.y, B.y, P.y));
}


inline point project(const point &P, const point &P1, const point &P2) {
	return P1 + (P2 - P1) * (dot(P2 - P1, P - P1) / norm2(P2 - P1));
}

inline point reflect(const point &P, const point &P1, const point &P2) {
	return project(P, P1, P2) * 2.0 - P;
}

inline double point_to_line(const point &P, const point &A, const point &B) {
	// return abs(cross(B - A, C - A) / norm(B - A));
	return dist(P, project(P, A, B));
}

// line to line intersection
// A, B difine the first line
// C, D define the second line
inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

inline point rotate_point(const point &P, double angle) {
	return point(P.x * cos(angle) - P.y * sin(angle), P.y * cos(angle) + P.x * sin(angle));
}

inline point circle_center(const point &A, const point &B, const point &C) {
	assert(abs(cross(B - A, C - A)) > EPS); // no colinear
	return intersect((A + B) / 2.0, (A + B) / 2.0 + rotate_point(B - A, PI),
									 (B + C) / 2.0, (B + C) / 2.0 + rotate_point(C - B, PI));
}

inline pair <point, point> point_circle_tangent(const point &P, const point &C, const double r) {
	double d = dist(P, C);
	double l = sqrt(d * d - r * r);
	double a = asin(r / d);
	return make_pair(P + rotate_point((C - P) * (l / d), a), P + rotate_point((C - P) * (l / d), -a));
}

inline vector <point> line_circle_intersect(const point &A, const point &B, const point &C, const double r) {
	point PC = project(C, A, B);
	double d = dist(C, PC);
	if (d > r + EPS) {
		return vector <point> ();
	}
	if (abs(d - r) < EPS) {
		return vector <point> (1, PC);
	}
	double l = sqrt(r * r - d * d);
	vector <point> res(2);
	double dAB = dist(A, B);
	res[0] = PC + (B - A) * (l / dAB);
	res[1] = PC - (B - A) * (l / dAB);
	return res;
}

inline double signed_area(const vector <point> &polygon) {
	double res = 0.0;
	int n = polygon.size();
	for (int i = 0; i < n; i++) {
		int j = (i + 1 == n) ? 0 : i + 1;
		res += cross(polygon[i], polygon[j]);
	}
	return 0.5 * res;
}

inline double abs_area(const vector <point> &polygon) {
	return abs(signed_area(polygon));
}

inline double closest_pair_of_points(vector <point> pts) {
	sort(pts.begin(), pts.end(), compare_by_x());
	multiset <point> candidates;
	int n = pts.size();
	double res = INF;
	for (int i = 0, last = 0; i < n; i++) {
		while (last < i && pts[i].x - pts[last].x >= res + EPS) {
			candidates.erase(candidates.find(pts[last]));
			last++;
		}
		set <point> :: iterator lo = candidates.lower_bound(point(-INF, pts[i].y - res - EPS));
		set <point> :: iterator hi = candidates.upper_bound(point(INF, pts[i].y + res + EPS));
		while (lo != hi) {
			res = min(res, dist(pts[i], *lo));
			lo++;
		}
		candidates.insert(pts[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);

	int n;
	cin >> n;

	vector <point> pts(n);
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}

	double answer = closest_pair_of_points(pts);
	cout << fixed << answer << "\n";
}

