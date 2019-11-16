// 2015 United Kingdom and Ireland Programming Contest (UKIEPC 2015)
// 100800B

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	//freopen("dat.txt", "r", stdin);
	int n;
	double g;
	cin >> n >> g;
	vector <double> d(n), a(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> a[i];
		a[i] = a[i] * M_PI / 180.0;
	}
	for (int i = 0; i < n; i++) {
		double v = 0;
		for (int j = i; j < n; j++) {
			v = sqrt(v * v + 2.0 * g * cos(a[j]) * d[j]);
		}
		cout << fixed << v << "\n";
	}
}
