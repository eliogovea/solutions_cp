#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000000;

ll sum[N + 5];
int ans[N + 5];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + i;
	}
	for (int i = 2; i <= N; i++) {
		ll tmp = 2 * sum[i - 1] + i;
		ll lo = 1;
		ll hi = 1e7;
		bool ok = false;
		int pos;
		while (lo <= hi) {
            ll mid = (lo + hi) / 2LL;
            ll val = mid * (mid + 1) / 2LL;
            if (val == tmp) {
                pos = mid;
                ok = true;
                break;
            }
            if (val < tmp) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
		}
		if (ok && pos <= N) {
            ans[pos]++;
		}
	}
	for (int i = 1; i <= N; i++) {
        ans[i] += ans[i - 1];
	}
	while (cin >> n && n) {
		cout << ans[n] << "\n";
	}
}
