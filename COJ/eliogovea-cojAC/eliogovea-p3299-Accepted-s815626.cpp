#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		ll lo = 1;
		ll hi = 1e8;
		ll p1 = -1;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2LL;
			if (mid * (mid + 1) / 2LL >= a) {
				p1 = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		lo = 1;
		hi = 1e8;
		ll p2 = -1;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2LL;
			if (mid * (mid + 1) / 2LL <= b) {
				p2 = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (p1 == -1 || p2 == -1) {
			cout << "0\n";
			continue;
		} else {
			cout << p2 - p1 + 1 << "\n";
		}
	}
}
