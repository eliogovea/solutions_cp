// Problem: pace=1&num=1084
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

double l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	cin >> l >> r;
	if (r <= l / 2.0) {
		cout << fixed << M_PI * r * r << "\n";
		return 0;
	}
	if (r >= l * sqrt(2.0) / 2.0) {
		cout << fixed << l * l << "\n";
		return 0;
	}
	double a = l / 2.0 / r;
	double b = sqrt(1.0 - a * a);
	double c = 2.0 * acos(a);
	double d = 2.0 * a * b;
	double area = r * r * (M_PI - 2.0 * c + 2.0 * d);
	cout << fixed << area << "\n";
}
