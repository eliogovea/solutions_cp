#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	double C = sqrt(3.0) - 0.5 * 3.14;
	int t;
	cin >> t;
	while (t--) {
		double r;
		cin >> r;
		cout << fixed << C * r * r << "\n";
	}
}