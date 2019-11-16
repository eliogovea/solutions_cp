#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long d, m, d1, n, d2;

	cin >> d >> m >> d1 >> n >> d2;

	if (d >= d1) {
		cout << "-1\n";
		return 0;
	}

	auto calck = [](long long d, long long x) {
		long long v = (x + x - d - 1) / (x - d);
		int l = 0;
		while ((1LL << l) < v) {
			l++;
		}
		return l;
	};

	int k1 = calck(d, d1);

	if (k1 <= m) {
		cout << k1 << "\n";
		return 0;
	}

	d = (1LL << m) * (d - d1) + d1;

	if (d >= d2) {
		cout << "-1\n";
		return 0;
	}

	int k2 = calck(d, d2);

	if (k2 <= n) {
		cout << m + k2 << "\n";
	} else {
		cout << "-1\n";
	}
}
