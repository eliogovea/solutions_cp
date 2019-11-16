#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n, a[105];
int cntl, cntr;
ll l[1000005], r[1000005];
 
// l guarda a * b + c
// r guarda (e + f) * d con d != 0
 
ll ans;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
        l[cntl++] = a[i] * a[j] + a[k];
				if (a[k] != 0) {
				  r[cntr++] = (a[i] + a[j]) * a[k];
				}
			}
		}
	}
	sort(l, l + cntl);
	sort(r, r + cntr);
	for (int i = 0; i < cntl; i++) {
		ans += upper_bound(r, r + cntr, l[i]) - lower_bound(r, r + cntr, l[i]);
	}
	cout << ans << "\n";
}
