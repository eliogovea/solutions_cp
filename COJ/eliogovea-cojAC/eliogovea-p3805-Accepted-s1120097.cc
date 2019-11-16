#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double g = 9.8;
const double PI = 2.0 * asin(1.0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);

	long long ix1, ix2, iy1, iy2, iv;
	while (cin >> ix1 >> iy1 >> ix2 >> iy2 >> iv) {
		long long ix = ix2 - ix1;
		long long iy = iy2 - iy1;

		if (100LL * iv * iv * iv * iv < 98LL * 98LL * ix * ix + 2LL * 980LL * iy * iv * iv) {
			cout << "Impossible\n";
		} else {
			double x = (double)ix;
			double y = (double)iy;
			double v = (double)iv;

			double a = g * x * x / (2.0 * v * v);
			double b = -x;
			double c = g * x * x / (2.0 * v * v) + y;

			double d = b * b - 4.0 * a * c;
			double t1 = (-b - sqrt(d)) / (2.0 * a);
			double t2 = (-b + sqrt(d)) / (2.0 * a);
			double a1 = atan(t1) * 180.0 / PI;
			double a2 = atan(t2) * 180.0 / PI;
			if (a1 > a2) {
                swap(a1, a2);
			}
			if (a1 < -EPS) {
                if (a2 < -EPS || a2 > 90.0 + EPS) {
                    cout << "Impossible\n";
                } else {
                    if (a2 > 90.0) {
                        a2 = 90.0;
                    }
                    if (a2 < 0.0) {
                        a2 = 0.0;
                    }
                    cout << fixed << a2 << "\n";
                }
			} else if (a1 > 90.0 + EPS) {
                cout << "Impossible\n";
			} else {
			    if (a1 > 90.0) {
                    a1 = 90.0;
			    }
			    if (a1 < 0.0) {
                    a1 = 0.0;
			    }
                cout << fixed << a1 << "\n";
			}
		}
	}
}
