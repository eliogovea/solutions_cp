#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	int t;
	long double l, a;
	cin >> t;
	while (t--) {
		cin >> l >> a;
        a = a * M_PI / (long double)180.0;
		long double r = l * tan(a / (long double)2.0) / (long double)2.0;
		long double x = M_PI - a;
		long double total = (long double)M_PI * l * r / x;
		long double circle = M_PI * r * r;
		cout << fixed << double(total - circle) << "\n";
	}
}
