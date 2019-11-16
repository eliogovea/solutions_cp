#include <bits/stdc++.h>

using namespace std;

int t, n, x;
set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> x;
			s.insert(x);
		}
	}
	cout << s.size() << "\n";
}