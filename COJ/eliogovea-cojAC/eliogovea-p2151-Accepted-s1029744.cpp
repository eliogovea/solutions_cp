#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mx = 0;
		int sum = 0;
		while (n--) {
			int x;
			cin >> x;
			mx = max(mx, x);
			sum += x;
		}
		cout << sum - mx << "\n";
	}
}