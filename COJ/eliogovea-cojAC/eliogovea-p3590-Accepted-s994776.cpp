#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	string s;
	cin >> n >> s >> t;
	int p = 0;
	while (t--) {
		int r, l;
		cin >> r >> l;
		r %= n;
		p = (p + r) % n;
		l %= n;
		p = (p - l + n) % n;
	}
	for (int i = 0; i < n; i++) {
		cout << s[(p + i) % n];
	}
	cout << "\n";
}
