#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	const double g = 9.8;
	double m, t, p;
	while (cin >> m >> t >> p) {
		cout << fixed << -t * log(1.0 - p) / g << "\n";
	}
}
