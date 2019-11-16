#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

const int N = 105;

int n;
int x[N], y[N], r[N];

inline double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dx * dx + dy * dy <= r[j] * r[j]) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double d = dist(x[i], y[i], x[j], y[j]);
			double dx = x[j] - x[i];
			double dy = y[j] - y[i];
			if (fabs(d - (double(r[i] + r[j]))) < EPS) {
				double t = (double)r[i] / d;
				double xx = (double)x[i] + t * dx;
				double yy = (double)y[i] + t * dy;
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (dist(x[k], y[k], xx, yy) < (double)r[k] + EPS) {
						cnt++;
					}
				}
				ans = max(ans, cnt);
			} else if (d < (double)r[i] + r[j]) {
				double df = ((double)(r[i] * r[i] - r[j] * r[j])) / d;
				double a = (d + df) / 2.0;
				double t = a / d;
				double xx = (double)x[i] + t * dx;
				double yy = (double)y[i] + t * dy;
				double ndx = -dy;
				double ndy = dx;
				double l = sqrt((double(r[i] * r[i])) - a * a);
				t = l / d;
				double nxx = xx + ndx * t;
				double nyy = yy + ndy * t;
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (dist(nxx, nyy, x[k], y[k]) < (double)r[k] + EPS) {
						cnt++;
					}
				}
				ans = max(cnt, ans);
				nxx = xx - ndx * t;
				nyy = yy - ndy * t;
				cnt = 0;
				for (int k = 0; k < n; k++) {
					if (dist(nxx, nyy, x[k], y[k]) < (double)r[k] + EPS) {
						cnt++;
					}
				}
				ans = max(cnt, ans);
			}
		}
	}
    cout << ans << "\n";
}
