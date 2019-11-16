#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, g, p;
		cin >> n >> g >> p;

		vector <int> d(g), r(g);
		for (int i = 0; i < g; i++) {
			cin >> d[i] >> r[i];
		}

		vector <int> v(g);

		auto check = [&](long long x) {
			for (int i = 0; i < g; i++) {
				if (d[i] <= x) {
					v[i] = (long long)(x - d[i]) / r[i];
				} else {
					v[i] = 0;
				}
			}
			sort(v.begin(), v.end());
			long long s = 0;
			for (int i = 0; i < p; i++) {
				s += v[g - 1 - i];
			}
			/*
			cerr << "check: " << x << "\n";
			for (int i = 0; i < g; i++) {
				cerr << v[i] << " ";
			}
			cerr << "\n";
			cerr << s << " " << n << "\n";
			*/
			return (s >= n);
		};

		long long lo = 1;
		long long hi = 1;
		while (!check(hi)) {
			hi *= 2LL;
		}

		long long answer = hi;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2LL;
			if (check(mid)) {
				answer = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		cout << answer << "\n";

	}
}
