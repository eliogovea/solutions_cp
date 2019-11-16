#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;

inline void add(int & a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % M;
}

inline int power(int x, int n) {
	int y = 1;
	while (n) {
		if (n & 1) {
			y = mul(y, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> p >> n;

	int q = p - 1;

	int t = 0;
	int s = 0;


	vector <long long> divs;

	for (int d = 1; d * d <= q; d++) {
		if (q % d == 0) {
			divs.push_back(d);
			divs.push_back((long long)d * p);
			if (d * d < q) {
				divs.push_back(q / d);
				divs.push_back((long long)p * (q / d));
			}
		}
	}

	t = divs.size();

	if (n == 0) {
		s = (long long)q * t % M;
	} else {
		for (auto d : divs) {
			long long a1 = d + p - 1LL;
			long long a2 = (long long)p * (long long)q / d + p;
			if (n == 1) {
				add(s, a1 % M);
			} else {
				int an = mul(a2 % M, power(p, n - 2));
				add(s, an);
			}
		}
	}
	cout << t << " " << s << "\n";
}
