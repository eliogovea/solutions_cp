#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL n, a, b, c;
	cin >> n >> a >> b >> c;
	int r = n % 4LL;
	if (r == 0) {
		cout << "0\n";
		return 0;
	}
	LL x = 4 - r;
	LL ans = -1;
	for (int ca = 0; ca <= 50; ca++) {
		for (int cb = 0; cb <= 50; cb++) {
			for (int cc = 0; cc <= 50; cc++) {
				LL ct = n + 1LL * ca + 2LL * cb + 3LL * cc;
				if (ct % 4LL == 0) {
					LL cost = a * ca + b * cb + c * cc;
					if (ans == -1LL || cost < ans) {
						ans = cost;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}
