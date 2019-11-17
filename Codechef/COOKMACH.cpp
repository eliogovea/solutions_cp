#include <bits/stdc++.h>

using namespace std;

int a, b;

bool PowOf2(int x) {
	int lo = 0;
	int hi = 1 << 28;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if ((1 << mid) == x) {
			return true;
		}
		if ((1 << mid) < x) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return false;
}

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int ans = 0;
		while (!PowOf2(a)) {
			a >>= 1;
			ans++;
		}
		if (a >= b) {
			while (a != b) {
				a >>= 1;
				ans++;
			}
		} else {
			while (a != b) {
				a <<= 1;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}

