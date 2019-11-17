/// Geometry INT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(const LL x) {
	if (x < 0) {
		return -1;
	}
	if (x > 0) {
		return 1;
	}
	return 0;
}

struct point {
	LL x, y;
	point() {}
	point(LL _x, LL _y) : x(_x), y(_y) {}
};

bool operator < (const point &P, const point &Q) {
	if (P.y != Q.y) {
		return P.y < Q.y;
	}
	return P.x < Q.x;
}

void normalize(point &P) {
	assert(P.x != 0 || P.y != 0);
	LL g = __gcd(P.x, P.y);
	P.x /= g;
	P.y /= g;
}

point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point &P, const point &Q) {
	return point (P.x - Q.x, P.y - Q.y);
}

point operator * (const point &P, const LL k) {
	return point(P.x * k, P.y * k);
}

point operator / (const point &P, const LL k) {
	assert(k != 0 && P.x % k == 0 && P.y % k == 0);
	return point(P.x / k, P.y / k);
}

inline LL dot(const point &P, const point &Q) {
	return P.x * Q.x + P.y * Q.y;
}

inline LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline bool is_in(LL x, LL a, LL b) {
	if (a > b) {
		swap(a, b);
	}
	return (a <= x && x <= b);
}

inline bool is_in(const point &P, const point &A, const point &B) {
	if (cross(B - A, P - A) != 0) {
		return false;
	}
	return (is_in(P.x, A.x, B.x) && is_in(P.y, A.y, B.y));
}

inline bool segment_segment_intersect(const point &A, const point &B, const point &C, const point &D) {
	if (cross(B - A, D - C) == 0) { // lines are parallel
		return (is_in(A, C, D) || is_in(B, C, D) || is_in(C, A, B) || is_in(D, A, B));
	}
	if (sign(cross(C - A, B - A)) * sign(cross(D - A, B - A)) > 0) {
		return false;
	}
	if (sign(cross(A - C, D - C)) * sign(cross(B - C, D - C)) > 0) {
		return false;
	}
	return true;
}

inline bool is_convex(const vector <point> &polygon) {
	int n = polygon.size();
	assert(n >= 3);
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		int k = (i + 2) % n;
		if (sign(cross(polygon[j] - polygon[i], polygon[k] - polygon[i])) < 0) {
			return false;
		}
	}
	return true;
}

const int OUT = 0;
const int ON = 1;
const int IN = 2;
/// 0 outside, 1 boundary, 2 inside
inline int point_inside_polygon(const point &P, const vector <point> &polygon) {
	int n = polygon.size();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		point A = polygon[i];
		point B = polygon[(i + 1) % n];
		if (is_in(P, A, B)) {
			return ON;
		}
		if (B.y < A.y) {
			swap(A, B);
		}
		if (P.y < A.y || B.y <= P.y || A.y == B.y) {
			continue;
		}
		if (sign(cross(B - A, P - A)) > 0) {
			cnt++;
		}
	}
	if (cnt & 1) {
		return IN;
	}
	return OUT;
}

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
// test OK
void test_segment_segment_intersection() {
	int q;
	cin >> q;
	while (q--) {
		point A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		cout << (segment_segment_intersect(A, B, C, D) ? "1" : "0") << "\n";
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// test OK
void test_is_convex() {
	int n;
	cin >> n;
	vector <point> polygon(n);
	for (int i = 0; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}
	cout << (is_convex(polygon) ? "1" : "0") << "\n";
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
// test ???
void test_point_inside_polygon() {
	int n;
	cin >> n;
	vector <point> polygon(n);
	for (int i = 0; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}
	int q;
	cin >> q;
	while (q--) {
		point P;
		cin >> P.x >> P.y;
		cout << point_inside_polygon(P, polygon) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// test_segment_segment_intersection();
	// test_is_convex();
	test_point_inside_polygon();
}

