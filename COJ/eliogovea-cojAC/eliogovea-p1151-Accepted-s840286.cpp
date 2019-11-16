#include <bits/stdc++.h>

using namespace std;

const int N = 32000;

bool criba[N + 5];

vector <int> p;

vector <int> fact(int n) {
	vector <int> res;
	for (int i = 0; p[i] * p[i] <= n; i++) {
		if (n % p[i] == 0) {
			res.push_back(p[i]);
			while (n % p[i] == 0) {
				n /= p[i];
			}
		}
	}
	if (n > 1) {
		res.push_back(n);
	}
	return res;
}

int t, n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j += i) {
			criba[j] = true;
		}
	}
	p.push_back(2);
	for (int i = 3; i <= N; i += 2) {
		if (!criba[i]) {
			p.push_back(i);
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		vector <int> fp = fact(n);
		int ans = b - a + 1;
		int sz = fp.size();
		for (int i = 1; i < (1 << sz); i++) {
			int x = 1;
			int y = 1;
			for (int j = 0; j < sz; j++) {
				if (i & (1 << j)) {
					x *= fp[j];
					y *= -1;
				}
			}
			int cnt = b / x - (a - 1) / x;
			ans += y * cnt;
		}
		cout << ans << "\n";
	}
}
