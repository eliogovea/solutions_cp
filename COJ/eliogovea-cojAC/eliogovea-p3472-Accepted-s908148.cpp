#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	vector <int> a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	bool ok = false;;
	if (m == n) {
		ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				ok = false;
				break;
			}
		}
	}
	if (ok) {
		cout << "=\n";
		return 0;
	}
	double x = 0.0;
	double y = 0.0;
	for (int i = 0; i < n; i++) {
		x += log((double)a[i]);
	}
	for (int i = 0; i < m; i++) {
		y += log((double)b[i]);
	}
	cout << (x < y ? "<" : ">") << "\n";
}
