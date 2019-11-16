#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100005;
 
int t;
int n, c;
int x[N];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		int lo = 1;
		int hi = 1000000000;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int last = 0;
			int cc = 1;
			for (int i = 1; i < n; i++) {
				if (x[i] - x[last] >= mid) {
					cc++;
					last = i;
				}
			}
			if (cc >= c) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}
 
