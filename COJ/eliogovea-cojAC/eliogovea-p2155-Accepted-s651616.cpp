#include <iostream>
#include <cmath>
//#include <cstdio>

using namespace std;

const double eps = 1e-7, g = 9.806, pi = 2.0 * acos(0.0);

int tc, cas;
double d, v;

int main() {
    //freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(2);
	cin >> tc;
	while (tc--) {
		cin >> d >> v;
		cout << "Scenario #" << ++cas << ": ";
		if (v * v / g + eps < d) cout << "-1";
		else cout << fixed << 90.0 * asin(d * g / (v * v)) / pi;
		cout << "\n";
	}
}
