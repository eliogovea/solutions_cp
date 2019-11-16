#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 1;
		if (s[0] != '1') {
			ans = 0;
		}
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != '0') {
				ans = 0;
				break;
			}
		}
		cout << ans << "\n";
	}
}