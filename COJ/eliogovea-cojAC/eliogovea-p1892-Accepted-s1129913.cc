#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(const LL x) {
	return (x < 0) ? -1 : (x > 0);
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

bool operator == (const point &P, const point &Q) {
	return !(P < Q) && !(Q < P);
}

inline point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

inline point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

inline LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

bool intersect(point A, point B, point C, point D) {
	if (cross(B - A, D - C) == 0) {
		if (cross(B - A, C - A) == 0) {
			if (B < A) {
				swap(A, B);
			}
			if (D < C) {
				swap(C, D);
			}
			if (C < A) {
				swap(A, C);
				swap(B, D);
			}
			return !(B < C);
		}
		return false;
	}
	if (sign(cross(C - A, B - A)) * sign(cross(D - A, B - A)) == 1) {
		return false;
	}
	if (sign(cross(A - C, D - C)) * sign(cross(B - C, D - C)) == 1) {
		return false;
	}
	return true;
}

inline double dist(const point &P, const point &Q) {
	double dx = P.x - Q.x;
	double dy = P.y - Q.y;
	return hypot(dx, dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	
	point A, B, C, D;
	int cas = 1;
	while (cin >> A.x >> A.y >> B.x >> B.y) {
		if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0) {
			break;
		}
		cin >> C.x >> C.y >> D.x >> D.y;
		double answer = 0.5 * dist(A, B);
		if (intersect(A, B, C, D)) {
			answer = 0.5 * (min(dist(A, C) + dist(C, B), dist(A, D) + dist(D, B)));
		}
		cout << "Case " << cas++ << ": " << fixed << answer << "\n";
	}

}