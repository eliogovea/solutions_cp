#include <bits/stdc++.h>

using namespace std;

const double g = 9.806;
const double pi = 2.0 * acos(0.0);
const double EPS = 1e-9;

int t;
double d, u, v;

inline double calc(double angle) {
	return (v * v * sin(2.0 * angle) + 2.0 * u * v * sin(angle)) / g;
}

double solve(double d, double v, double u) {
	double x = (-u + sqrt(u * u + v * v) / (4.0 * v));
	if (x <= -EPS || x >= 1.0 + EPS) {
		double lo = 0.0;
		double hi = pi / 2.0;
		for (int it = 0; it < 200; it++) {
			double mid = (lo + hi) / 2.0;
			if (calc(mid) < d) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		double ans = (lo + hi) / 2.0;
		if (fabs(calc(ans) - d) < EPS) {
			return ans;
		}
		return -1;
	}
	double lo = 0.0;
	double hi = acos(x);
	if (calc(lo) <= d + EPS && calc(hi) >= d - EPS) {
		for (int it = 0; it < 200; it++) {
			double mid = (lo + hi) / 2.0;
			if (calc(mid) < d) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		double ans = (lo + hi) / 2.0;
		if (fabs(calc(ans) - d) < EPS) {
			return ans;
		}
	}
	lo = acos(x);
	hi = pi / 2.0;
	if (calc(lo) >= d - EPS && calc(hi) <= d + EPS) {
		for (int it = 0; it < 200; it++) {
			double mid = (lo + hi) / 2.0;
			if (calc(mid) < d) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		double ans = (lo + hi) / 2.0;
		if (fabs(calc(ans) - d) < EPS) {
			return ans;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> d >> u >> v;
		double ans = solve(d, u, v);
		cout << "Scenario #" << cas << ": ";
		if (ans < 0) {
			cout << "-1\n";
		} else {
			cout << fixed << ans * 180.0 / pi << "\n";
		}
	}
}
