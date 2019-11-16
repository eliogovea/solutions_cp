#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1048576 + 5;

int n;
ll v, s;
ll a[50], b[50], c[N];
int sa, sb, sc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen(dat.txt, "r", stdin);
	while (cin >> n >> s) {
		sa = sb = 0;
		for (int i = 0; i < n; i++) {
			cin >> v;
			if (i < n / 2) {
				a[sa++] = v;
			} else {
				b[sb++] = v;
			}
		}
		for (int i = 0; i < (1 << sa); i++) {
			c[i] = 0;
			for (int j = 0; j < sa; j++) {
				if (i & (1 << j)) {
					c[i] += a[j];
				}
			}
		}
		sort(c, c + (1 << sa));
		ll ans = 0;
		for (int i = 0; i < (1 << sb); i++) {
			ll sum = 0;
			for (int j = 0; j < sb; j++) {
				if (i & (1 << j)) {
					sum += b[j];
				}
			}
			ans += upper_bound(c, c + (1 << sa), s - sum) - lower_bound(c, c + (1 << sa), s - sum);
		}
		if (s == 0) {
			ans--;
		}
		cout << ans << "\n";
	}
}
