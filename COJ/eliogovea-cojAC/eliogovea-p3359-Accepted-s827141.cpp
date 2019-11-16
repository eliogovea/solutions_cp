#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll x[10], y[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	for (int i = 0; i < 4; i++) {
		ll tmp = y[i];
		for (int j = 0; j < 4; j++) {
			if (j == i) {
				continue;
			}
			tmp *= (n - x[j]);
		}
		for (int j = 0; j < 4; j++) {
			if (j == i) {
				continue;
			}
			tmp /= (x[i] - x[j]);
		}
		ans += tmp;
	}
	cout << ans << "\n";
}
