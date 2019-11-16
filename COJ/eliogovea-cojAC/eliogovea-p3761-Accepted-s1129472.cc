#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct point {
	LL x, y;
	point() {}
	point(LL _x, LL _y)
		: x(_x), y(_y) {}
};

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

inline LL dot(const point &P, const point &Q) {
	return P.x * Q.x + P.y * Q.y;
}

inline LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline LL abs_2(const point &P) {
	return dot(P, P);
}

inline double abs(const point &P) {
	return sqrt((double)dot(P, P));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	
	point A, B, C;
	LL r;
	
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> r;
	
	if (cross(B - A, C - A) * cross(B - A, C - A) >= r * r * abs_2(B - A)) {
		double answer = abs(B - A);
		cout << fixed << answer << "\n";
		return 0;
	}
	
	if (dot(B - A, C - A) <= 0 || dot(A - B, C - B) <= 0) {
		double answer = abs(B - A);
		cout << fixed << answer << "\n";
		return 0;
	}

	double sl = abs(B - A);
	double h = (double)abs(cross(B - A, C - A)) / abs(B - A);
	double ic = 2.0 * sqrt((double)r * r - h * h);
	double angle = 2.0 * acos(h / (double)r);
	
	double answer = (sl - ic) + angle * (double)r;
	
	cout << fixed << answer << "\n";
}