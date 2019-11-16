#include <bits/stdc++.h>

using namespace std;

inline double S(double n) {
	return sqrt((n + 1.0) * ( 2.0 * n * (2.0 * n + 1.0)  / 3.0 - n * (n + 1.0) ) / (n - 1.0));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	int n;
	while (cin >> n && n) {
		cout << fixed << S(n) << "\n";
	}
}
