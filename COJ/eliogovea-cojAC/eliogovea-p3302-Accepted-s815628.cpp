#include <bits/stdc++.h>

using namespace std;

int t;
double l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(4);
	cin >> t;
	while (t--) {
		cin >> l;
		cout << fixed << 1.0 / (l * l) << "\n";
	}
}