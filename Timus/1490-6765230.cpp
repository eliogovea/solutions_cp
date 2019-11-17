// Problem: pace=1&num=1490
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long r;
	cin >> r;
	long long ans = 0;
	for (long long y = 0; y < r; y++) {
		long long lo = 0;
		long long hi = r - 1LL;
		long long x = lo;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2LL;
			if (mid * mid + y * y < r * r) {
				x = mid;
				lo = mid + 1LL;
			} else {
				hi = mid - 1LL;
			}
		}
		ans += x + 1LL;
	}
	ans *= 4LL;
	cout << ans << "\n";
}
