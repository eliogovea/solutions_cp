#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

struct order {
	int s, e, v;
};

bool operator < (const order &a, const order &b) {
	if (a.e != b.e) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

int t;
int n;
order a[N];

int dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].s >> a[i].e >> a[i].v;
			a[i].e += a[i].s;
		}
		sort(a + 1, a + n + 1);
		dp[0] = 0;
		dp[1] = a[1].v;
		for (int i = 2; i <= n; i++) {
			int lo = 1;
			int hi = i - 1;
			int pos = 0;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (a[mid].e < a[i].s) {
					pos = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			dp[i] = max(dp[i - 1], dp[pos] + a[i].v);
		}
		cout << dp[n] << "\n";
	}
}
