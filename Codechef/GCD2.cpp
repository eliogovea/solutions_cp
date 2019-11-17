#include <bits/stdc++.h>

using namespace std;

int t, a;
string b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == 0) {
			cout << b << "\n";
			continue;
		}
		int r = 0;
		for (int i = 0; b[i]; i++) {
			r = ((10 * r) + b[i] - '0') % a;
		}
		cout << __gcd(a, r) << "\n";
	}
}

