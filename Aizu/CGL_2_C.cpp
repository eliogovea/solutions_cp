#include <bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

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

inline point project(const point &P, const point &P1, const point &P2) {
	return P1 + (P2 - P1) * (dot(P2 - P1, P - P1) / norm2(P2 - P1));
}

inline point reflect(const point &P, const point &P1, const point &P2) {
	return project(P, P1, P2) * 2.0 - P;
}

inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
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
		point answer = intersect(A, B, C, D);
		cout << fixed << answer.x << " " << fixed << answer.y << "\n";
	}
}

