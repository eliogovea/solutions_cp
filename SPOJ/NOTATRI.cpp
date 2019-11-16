#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2005;
 
int n;
int l[N];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}
		sort(l, l + n);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int sum = l[i] + l[j];
				int pos = upper_bound(l, l + n, sum) - l;
				ans += n - pos;
			}
		}
		cout << ans << "\n";
	}
}
