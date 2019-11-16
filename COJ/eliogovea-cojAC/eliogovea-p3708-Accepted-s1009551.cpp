#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long ve = n;
		long long vi = n * (n - 1LL) * (n - 2LL) * (n - 3LL) / 24LL;
		long long e = ((n + 1LL) * ve + 4 * vi) / 2LL;
		long long ans = e - ve - vi + 1LL;
		cout << ans << "\n";
	}
}
