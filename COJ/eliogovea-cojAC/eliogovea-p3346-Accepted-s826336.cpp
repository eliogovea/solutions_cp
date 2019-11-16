#include <bits/stdc++.h>

using namespace std;

int n, b, t;
int a[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> t;
	int x;
	while (t--) {
		cin >> x;
		int cnt = b / x;
		int ans = upper_bound(a, a + n, cnt) - a;
		cout << n - ans << "\n";
	}
}
