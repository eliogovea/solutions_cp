// Problem: pace=1&num=1192
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const double pi = 3.1415926535;

double v, a, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> v >> a >> k;
	a = a * pi / 180.0;
	cout.precision(2);
	double ans = v * v * sin(2.0 * a) * (k / (k - 1.0)) / 10.0;
	cout << fixed << ans << "\n";
}
