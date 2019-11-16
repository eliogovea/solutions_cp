#include <bits/stdc++.h>

using namespace std;

long long n, p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cas = 1;
	while (cin >> n >> p) {
		if (n == 0 && p == 0) {
			break;
		}
		bool ok = true;
		while (n) {
			if (n % p > 1) {
				ok = false;
				break;
			}
			n /= p;
		}
		cout << "Case #" << cas++ << ": " << (ok ? "yes" : "no") << "\n";
	}
}
