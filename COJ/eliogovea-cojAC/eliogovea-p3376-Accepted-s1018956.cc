#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> x(n), y(n);
	vector <pair <int, pair <int, long long> > > v;
	v.reserve(n * n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		for (int j = 0; j < i; j++) {
			v.emplace_back(make_pair(x[i] + x[j], make_pair(y[i] + y[j], (long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j]) * (y[i] - y[j]))));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0, j = 0; i <= v.size(); i++) {
		if (v[i] != v[j]) {
			ans += ((long long)(i - j) * (i - j - 1LL)) / 2LL;
			j = i;
		}
	}
	cout << ans << "\n";
}
