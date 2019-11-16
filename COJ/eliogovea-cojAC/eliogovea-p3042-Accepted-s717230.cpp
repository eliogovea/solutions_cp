#include <iostream>
#include <algorithm>

using namespace std;

int n, h[1000005], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	sort(h, h + n);
	ans = n;
	for (int i = 0; i < n; i++) {
		int cnt = h[i] + n - 1 - i;
		if (cnt < ans) ans = cnt;
	}
	cout << ans << "\n";
}
