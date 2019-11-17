#include <bits/stdc++.h>

using namespace std;

int t;
int n, a[100005];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int pos = upper_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
			if (pos == ans.size()) {
				ans.push_back(a[i]);
			} else {
				ans[pos] = a[i];
			}
		}
		cout << ans.size();
		for (int i = 0; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << "\n";
	}
}

