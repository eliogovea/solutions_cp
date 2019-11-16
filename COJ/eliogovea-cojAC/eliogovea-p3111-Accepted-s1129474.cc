#include <bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y)
		: x(_x), y(_y) {}
};

point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point &P, double k) {
	return point(P.x * k, P.y * k);
}

point operator / (const point &P, double k) {
	return point(P.x / k, P.y / k);
}

inline double cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

point centroid(const vector <point> &g) {
	int n = g.size();
	point C(0, 0);
	double area = 0.0;
	for (int i = 1; i < n - 1; i++) {
		int j = (i + 1 == n) ? 0 : i + 1;
		double a = cross(g[i] - g[0], g[j] - g[0]);
		area += a;
		C = C + (g[0] + g[i] + g[j]) * a;
	}
	C = C / (3.0 * area);
	return C;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	
	int n;
	cin >> n;
	
	vector <point> g(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i].x >> g[i].y;
	}
	
	point answer = centroid(g);
	
	cout << "(" << fixed << answer.x << ";" << fixed << answer.y << ")\n";
}