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

// returns true if P belongs in segment AB
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

inline double point_to_segment(const point &P, const point &A, const point &B) {
	point PP = project(P, A, B);
	if (is_in(A, B, PP)) {
		return dist(P, PP);
	}
	return min(dist(P, A), dist(P, B));
}

// line to line intersection
// A, B difine the first line
// C, D define the second line
inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

inline double segment_to_segment(const point &A, const point &B, const point &C, const point &D) {
	point I = intersect(A, B, C, D);
	if (is_in(A, B, I) && is_in(C, D, I)) {
		return 0.0;
	}
	return min(min(point_to_segment(A, C, D), point_to_segment(B, C, D)),
						 min(point_to_segment(C, A, B), point_to_segment(D, A, B)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

	int q;
	cin >> q;

	while (q--) {
		point A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		double answer = segment_to_segment(A, B, C, D);
		cout << fixed << answer << "\n";
	}
}

