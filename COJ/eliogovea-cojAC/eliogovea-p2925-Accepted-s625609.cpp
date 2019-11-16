#include <bits/stdc++.h>
using namespace std;

int tc, a, b, s;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		s = 0;
		while (a > b) s++, a >>= 1;
		cout << s + b - a << "\n";
	}
}
