#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cin >> t;
	while (t--) {
		cin >> n;
		n--;
		cout << "(1.00;" << fixed << 0.25 * (2.0 * n + 1.0) << ")\n";
	}
}
