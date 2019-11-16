#include <bits/stdc++.h>
using namespace std;

const int mod = 1000;

int exp(int x, int n) {
	int r = 1;
	while (n) {
		if (n & 1) r = (r * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return r;
}

int n, sol, lg;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		if (n < 0) cout << "0\n";
		else if (n == 0) cout << "1\n";
		else if (n == 1) cout << "6\n";
		else if (n == 2) cout << "36\n";
		else {
			sol = exp(6, n);
			lg = (int)log10(sol) + 1;
            if (lg == 1) cout << "00";
			else if (lg == 2) cout << "0";
			cout << sol << '\n';
		}
	}
}
