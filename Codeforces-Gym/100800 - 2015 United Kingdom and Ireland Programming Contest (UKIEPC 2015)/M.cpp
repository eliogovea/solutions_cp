// 2015 United Kingdom and Ireland Programming Contest (UKIEPC 2015)
// 100800M

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	vector <long long> t(m);
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	vector <long long> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	set <pair <long long, long long> > speeds;
	vector <long long> dists;
	for (int i = 0; n - (i + 1) >= m - 1; i++) {
		long long dx = x[i + 1] - x[i];
		long long dt = t[1] - t[0];
		long long g = __gcd(dx, dt);
		dx /= g;
		dt /= g;
		//cerr << i << " " << dx << " " << dt << "\n";
		bool ok = true;
		for (int j = i + 2; j < i + m; j++) {
			long long dxx = x[j] - x[i];
			long long dtt = t[j - i] - t[0];
			long long gg = __gcd(dxx, dtt);
			dxx /= gg;
			dtt /= gg;
			//cerr << "  " << j << " " << dxx << " " << dtt << "\n";
			if (dxx != dx || dtt != dt) {
				ok = false;
				break;
			}
		}
		if (ok) {
			speeds.insert(make_pair(dx, dt));
			dists.push_back(x[i + 1] - x[i]);
		}
	}
	cout << speeds.size() << "\n";
	sort(dists.begin(), dists.end());
	dists.erase(unique(dists.begin(), dists.end()), dists.end());
	for (int i = 0; i < dists.size(); i++) {
		cout << dists[i];
		if (i + 1 < dists.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}
