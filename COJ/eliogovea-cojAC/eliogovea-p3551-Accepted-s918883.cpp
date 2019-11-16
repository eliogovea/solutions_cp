#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-14;

int t;
double r, k;

inline double f(double angle) {
	double A1 = (angle - sin(angle)) / 2.0;
	double A2 = M_PI - A1;
	return A1 / A2;
}

double solve(double r, double k) {
	double lo = 0;
	double hi = M_PI;
	for (int it = 0; it < 400; it++) {
		double mid = (lo + hi) / 2.0;
		if (f(mid) < k) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return (lo + hi) / 2.0;
}

int main() {
	
	
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		// cin >> r >> k;
		scanf("%lf%lf", &r, &k);
		double angle = solve(r, k);
		double x = r * cos(angle);
		double y = r * sin(angle);
		//cout << fixed << x << " " << fixed << y << "\n";
		printf("%.5lf %.5lf\n", x, y);
	}
}
