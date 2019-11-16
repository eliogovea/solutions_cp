// Problem: pace=1&num=1021
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int sa, sb, a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> sa;
	for (int i = 0; i < sa; i++) {
		cin >> a[i];
	}
	sort(a, a + sa);
	cin >> sb;
	bool ok = false;
	for (int i = 0; i < sb; i++) {
		cin >> b[i];
		if (!ok) {
			int tmp = 10000 - b[i];
			ok |= (*lower_bound(a, a + sa, tmp) == tmp);
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
}
