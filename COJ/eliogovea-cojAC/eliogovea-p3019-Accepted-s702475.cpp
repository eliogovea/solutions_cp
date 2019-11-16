#include <iostream>
#include <algorithm>

using namespace std;

int tc, n, a[55], b[55], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(lower_bound(b, b + n, a[i]) - b - i);
		cout << ans << "\n";
	}
}
