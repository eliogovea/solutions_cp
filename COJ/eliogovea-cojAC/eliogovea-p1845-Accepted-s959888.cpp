#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(4);
	double c = 0.5 * (1.0 + tan(M_PI / 3.0)) * (1.0 + tan(5.0 * M_PI / 12));
	int t;
	cin >> t;
	while (t--) {
		double r;
		cin >> r;
		cout << fixed << r * r * c << "\n";
	}
}
