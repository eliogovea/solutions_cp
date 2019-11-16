#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	sort(vals.begin(), vals.end());
	int ans = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (vals[i] - vals[j] > k) {
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
}