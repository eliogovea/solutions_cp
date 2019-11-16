#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> n;
	vector <string> ans;
	for (int i = 0; i < n; i++) {
		cin >> b;
		bool ok = true;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != '*' && a[j] != b[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans.push_back(b);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
