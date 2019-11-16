#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
int cas = 1;

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n > m) {
			swap(n, m);
		}
		if (n == 1 || m == 1) {
			cout << "Case " << cas++ << ": " << n * m << "\n";
			continue;
		}
		if (n <= 2 && m <= 2) {
			cout << "Case " << cas++ << ": " << n * m << "\n";
			continue;
		}
		int ans = m;
		if (n == 2) {
			int bst = m;
			if (m & 1) {
				bst = m + 1;
			} else if (m % 4 == 2) {
				int tmp = ((m / 4) + 1) * 4;
				if (tmp > bst) {
					bst = tmp;
				}
			}
			ans = bst;
		}
		int x = max(n * m / 2, n * m - n * m / 2);
		ans = max(ans, x);
		cout << "Case " << cas++ << ": " << ans << "\n";
	}
}
