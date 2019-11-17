/*****************************
*	Geometry Template          *
*	double !!!                 *
*	TODO: test everything!!!   *
*****************************/

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e17;
const double EPS = 1e-9;
const double PI = 2.0 * asin(1);

inline int sign(const double x) {
	if (abs(x) < EPS) {
		return 0;
	}
	if (x < 0.0) {
		return -1;
	}
	return 1;
}

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

struct compare_x {
	bool operator () (const point &P, const point &Q) {
		if (abs(P.x - Q.x) > EPS) {
			return P.x < Q.x;
		}
		return P.y < Q.y;
	}
};

struct compare_y {
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

inline int half_plane(const point &P) {
	if (abs(P.y) > EPS) {
		if (P.y > 0) {
			return 1;
		}
		return -1;
	}
	if (P.x > 0) {
		return 1;
	}
	return -1;
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

/// returns distance between P and Q
inline double dist(const point &P, const point &Q) {
	return sqrt(dot(P - Q, P - Q));
}

/// returns true if P belongs in segment AB
inline bool is_in(point A, point B, point P) {
	if (abs(cross(B - A, P - A)) > EPS) {
		return false;
	}
	return (is_in(A.x, B.x, P.x) && is_in(A.y, B.y, P.y));
}

/// projects point P in line P1, P2
inline point project(const point &P, const point &P1, const point &P2) {
	return P1 + (P2 - P1) * (dot(P2 - P1, P - P1) / norm2(P2 - P1));
}

inline point reflect(const point &P, const point &P1, const point &P2) {
	return project(P, P1, P2) * 2.0 - P;
}

/// distance from point P to the straigh line that passes through A and B
inline double point_to_line(const point &P, const point &A, const point &B) {
	// return abs(cross(B - A, C - A) / norm(B - A));
	return dist(P, project(P, A, B));
}

/// distance from point P to segment AB
inline double point_to_segment(const point &P, const point &A, const point &B) {
	point PP = project(P, A, B);
	if (is_in(A, B, PP)) {
		return dist(P, PP);
	}
	return min(dist(P, A), dist(P, B));
}

/// line to line intersection
/// A, B difine the first line
/// C, D define the second line
inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

/// distance between segmente AB and CD
inline double segment_to_segment(const point &A, const point &B, const point &C, const point &D) {
	point I = intersect(A, B, C, D);
	if (is_in(A, B, I) && is_in(C, D, I)) {
		return 0.0;
	}
	return min(min(point_to_segment(A, C, D), point_to_segment(B, C, D)),
						 min(point_to_segment(C, A, B), point_to_segment(D, A, B)));
}

/// rotate point P angle radians
inline point rotate_point(const point &P, double angle) {
	return point(P.x * cos(angle) - P.y * sin(angle), P.y * cos(angle) + P.x * sin(angle));
}

/// center of a circle that passes through points A, B, C
inline point circle_center(const point &A, const point &B, const point &C) {
	assert(abs(cross(B - A, C - A)) > EPS); // no colinear
	return intersect((A + B) / 2.0, (A + B) / 2.0 + rotate_point(B - A, PI),
									 (B + C) / 2.0, (B + C) / 2.0 + rotate_point(C - B, PI));
}

/// tangent to a circle with center in C and radius r, passes through P --> tested OK
inline pair <point, point> point_circle_tangent(const point &P, const point &C, const double r) {
	double d = dist(P, C);
	double l = sqrt(d * d - r * r);
	double a = asin(r / d);
	return make_pair(P + rotate_point((C - P) * (l / d), a), P + rotate_point((C - P) * (l / d), -a));
}

/// common tangents to a pair of circles
inline vector <pair <point, point> > common_tangents(const point &C1, const double r1, const point C2, const double r2) {
	/// TODO
}

/// line to circle intersection
inline vector <point> line_circle_intersect(const point &A, const point &B, const point &C, const double r) {
	point PC = project(C, A, B);
	double d = dist(C, PC);
	if (d > r + EPS) {
		return vector <point> ();
	}
	if (abs(d - r) <= EPS) {
		return vector <point> (1, PC);
	}
	double l = sqrt(r * r - d * d);
	vector <point> res(2);
	double dAB = dist(A, B);
	res[0] = PC + (B - A) * (l / dAB);
	res[1] = PC - (B - A) * (l / dAB);
	return res;
}

/// signed polygon area O(n)
inline double signed_area(const vector <point> &polygon) {
	double res = 0.0;
	int n = polygon.size();
	for (int i = 0; i < n; i++) {
		int j = (i + 1 == n) ? 0 : i + 1;
		res += cross(polygon[i], polygon[j]);
	}
	return 0.5 * res;
}

/// polygon area O(n)
inline double abs_area(const vector <point> &polygon) {
	return abs(signed_area(polygon));
}

/// closest pair of points O(n * log(n))
inline double closest_pair_of_points(vector <point> pts) {
	sort(pts.begin(), pts.end(), compare_x());
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

inline vector <point> minkowsky_sum(vector <point> &VA, const vector <point> &VB) {
	/// TODO
}

/// further pair of points
inline double convex_diameter(const vector <point> &polygon) {
	/// TODO
}

inline vector <point> normalize_polygon(vector <point> pts) {
	/// TODO
}

inline vector <point> convex_hull(vector <point> pts) {
	/// TODO
}

inline bool point_inside_polygon(const point &P, const vector <point> &polygon) {
	/// TODO
}

inline bool point_inside_convex(const point &P, const vector <point> &polygon) {
	/// TODO
}

struct line {
	double a, b, c;
};

inline vector <point> half_planes_intersection(const vector <line> &half_planes) {
	/// TODO
}

/// randomized algorithm -> expected time O(n)
inline pair <point, double> min_enclosing_circle(vector <point> pts) {
	///
}

inline point centroid(const vector <point> &polygon) {
	/// TODO
}

/// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
/// test ok
void testPolygonArea() {
    int n;
    cin >> n;
    vector <point> polygon(n);
    for (int i = 0; i < n; i++) {
        read(polygon[i]);
    }
    cout.precision(1);
    cout << fixed << abs_area(polygon) << "\n";
}

/// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
/// test ???
void test_line_circle_intersect() {
	point C;
	double r;
	cin >> C.x >> C.y >> r;
	int q;
	cin >> q;
	while (q--) {
		point A, B;
		cin >> A.x >> A.y >> B.x >> B.y;
		vector <point> answer = line_circle_intersect(A, B, C, r);
		assert(answer.size() != 0);
		if (answer.size() == 1) {
			answer.push_back(answer.back());
		}
		if (answer[1].x < answer[0].x || (answer[1].x == answer[0].x && answer[1].y < answer[0].y)) {
			swap(answer[0], answer[1]);
		}
		cout << fixed << answer[0].x << " " << fixed << answer[0].y << " " << fixed << answer[1].x << " " << fixed << answer[1].y << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

	// testPolygonArea();
	test_line_circle_intersect();
}

