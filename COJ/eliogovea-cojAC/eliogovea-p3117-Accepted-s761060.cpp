#include <iostream>
#include <algorithm>

using namespace std;

int n, c1[105], c2[105], ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> c2[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> c1[i];
		}
		ans = 0;
		sort(c1, c1 + n, greater<int>());
		sort(c2, c2 + n, greater<int>());
		for (int i = 0, j = 0; i < n && j < n; i++) {
      if (c2[j] > c1[i]) {
        ans++;
        j++;
      }
		}
		cout << ans << "\n";
	}
}
