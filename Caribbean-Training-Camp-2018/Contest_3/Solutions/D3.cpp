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

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int s = 0;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		add(s, a[i] + 1);
		ans = mul(ans, mul(i + 1, power(s, M - 2)));
	}

	cout << ans << "\n";
}
