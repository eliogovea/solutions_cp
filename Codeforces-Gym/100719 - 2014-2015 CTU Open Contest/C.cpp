// 2014-2015 CTU Open Contest
// 100719C

#include <bits/stdc++.h>

using namespace std;

int t, n, a[105], b[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int mx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx += min(a[i], b[j]);
			}
		}
		sort(a, a + n);
		sort(b, b + n);
		int mn = 0;
		int pa = n - 1;
		int pb = n - 1;
		while (pa >= 0 && pb >= 0) {
			if (a[pa] == b[pb]) {
				mn += a[pa];
				pa--;
				pb--;
			} else {
				if (a[pa] > b[pb]) {
					mn += a[pa];
					pa--;
				} else {
					mn += b[pb];
					pb--;
				}
			}
		}
		while (pa >= 0) {
			mn += a[pa];
			pa--;
		}
		while (pb >= 0) {
			mn += b[pb];
			pb--;
		}
		cout << "Minimalni budova obsahuje ";
		cout << mn;
		cout << " kostek, maximalni ";
		cout << mx;
		cout << " kostek.\n";
	}
}
