#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int t;
int n, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0, j = 0; i <= n; i++) {
			if (i == n || (i != 0 && a[i] < a[i - 1])) {
				long long d = i - j;
				j = i;
				ans += d * (d + 1LL) / 2LL;
			}
		}
		cout << ans << "\n";
	}
}

