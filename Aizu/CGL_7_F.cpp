#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

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

inline bool is_in(point A, point B, point P) {
	return (is_in(A.x, B.x, P.x) && is_in(A.y, B.y, P.y));
}

void read(point &P) {
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
	return norm(P - Q);
}

inline point project(const point &P, const point &P1, const point &P2) {
	return P1 + (P2 - P1) * (dot(P2 - P1, P - P1) / norm2(P2 - P1));
}

inline point reflect(const point &P, const point &P1, const point &P2) {
	return project(P, P1, P2) * 2.0 - P;
}

inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

inline point rotate_point(const point &P, double angle) {
	return point(P.x * cos(angle) - P.y * sin(angle), P.y * cos(angle) + P.x * sin(angle));
}

inline pair <point, point> point_circle_tangent(const point &P, const point &C, const double r) {
	double d = dist(P, C);
	double l = sqrt(d * d - r * r);
	double a = asin(r / d);
	return make_pair(P + rotate_point((C - P) * (l / d), a), P + rotate_point((C - P) * (l / d), -a));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

	point P, C;
	double r;

	cin >> P.x >> P.y >> C.x >> C.y >> r;

	pair <point, point> answer = point_circle_tangent(P, C, r);
	if (answer.first.x > answer.second.x || (answer.first.x == answer.second.x && answer.first.y > answer.second.y)) {
		swap(answer.first, answer.second);
	}
	cout << fixed << answer.first.x << " " << fixed << answer.first.y << "\n";
	cout << fixed << answer.second.x << " " << fixed << answer.second.y << "\n";
}

