#include <bits/stdc++.h>

using namespace std;

inline int power(int x, int n, int p) {
	int y = 1;
	while (n) {
		if (n & 1) {
			y = (long long)y * x % p;
		}
		x = (long long)x * x % p;
		n >>= 1;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc, a, b, p;
	cin >> tc;
	
	while (tc--) {
		cin >> p >> a >> b;
		b %= p;

		if (b == 0) {
			int t = min(10, p - (a == 0));
			cout << t << "\n";
			for (int i = (a == 0); i < t; i++) {
				cout << i;
				if (i + 1 < t) {
					cout << " ";
				}
			}
			cout << "\n";
		} else {
			int t = __gcd(p - 1, a);
			int cnt = min(10, t - 1);
			set <int> S;
			if (cnt > 0) {
				int e = (p - 1) / t;
				while (S.size() < cnt) {
					int x = 1 + (rand() % (p - 1));
					int y = power(x, e, p);

					if (y == 1) {
						continue;
					}
	
					// cerr << "size: " << S.size() << "\n";
					// cerr << "debug: " << x << " " << y << " " << power(y, a, p) << "\n";
					assert(power(y, a, p) == 1);
					S.insert(y);
				}
			}
			int c = 0;
			cout << cnt << "\n";
			for (auto & y : S) {
				int x = (long long)b * power(y - 1, p - 2, p) % p;
				assert(power((x + b) % p, a, p) == power(x, a, p));
				cout << x;
				c++;
				if (c < cnt) {
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
}
