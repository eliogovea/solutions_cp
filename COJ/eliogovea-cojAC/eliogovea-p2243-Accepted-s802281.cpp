#include <bits/stdc++.h>

using namespace std;

long long n, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n && n) {
		x = n;
		y = n * n + 1LL;
		if (n & 1LL) {
			y >>= 1LL;
		} else {
			x >>= 1LL;
		}
		cout << x * y << "\n";
	}
}
