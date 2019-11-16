// 2015 USP Try-outs
// 101047B

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 0) {
			for (int b = 2; b <= 16; b++) {
				cout << b;
				if (b != 16) {
					cout << " ";
				}
			}
			cout << "\n";
			continue;
		}
		vector <int> ans;
		for (int b = 2; b <= 16; b++) {
			vector <int> v;
			int x = n;
			while (x) {
				v.push_back(x % b);
				x /= b;
			}
			bool ok = true;
			for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
				if (v[i] != v[j]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans.push_back(b);
			}
		}
		if (!ans.size()) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i + 1 < ans.size()) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}