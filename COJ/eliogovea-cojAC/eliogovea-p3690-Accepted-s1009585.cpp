#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415927;

double solve(double r, double n) {
	double angle = 2.0 * PI / n;
	return r * r * cos(angle) * tan(angle / 2.0) * n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(13);
	long long r, n;
	while (cin >> r >> n) {
		if (r == 0 && n == 0) {
			break;
		}
		cout << fixed << solve(r, n) << "\n";
	}
}
