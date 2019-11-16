#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	if (n > m) {
        swap(n, m);
	}
	long long ans = 0;
	for (int dx = 1; dx < n; dx++) {
		for (int dy = 0; dy < m; dy++) {
			if (__gcd(dx, dy) == 1) {
				for (int i = 1; i * dx + dy < n && i * dy + dx < m; i++) {
					for (int j = 1; i * dx + j * dy < n && i * dy + j * dx < m; j++) {
						int w = i * dx + j * dy;
						int h = i * dy + j * dx;
						ans += (long long)(n - w) * (long long)(m - h);
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

/// O(n ^ 2 * log(n))
