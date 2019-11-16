#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200005;
 
int n;
char tipo[N];
int val[N];
 
int a[N], b[N];
int cnt[N];
 
int bit[N];
 
void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}
 
int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tipo[i] >> val[i];
		a[i] = val[i];
	}
	sort(a, a + n);
	int t = unique(a, a + n) - a; // numeros distintos
	for (int i = 0; i < n; i++) {
		b[i] = upper_bound(a, a + t, val[i]) - a;
	}
 
	for (int i = 0; i < n; i++) {
		if (tipo[i] == 'I') {
			if (cnt[b[i]] == 0) {
				update(b[i], 1);
				cnt[b[i]] = 1;
			}
		} else if (tipo[i] == 'D') {
			if (cnt[b[i]] == 1) {
				update(b[i], -1);
				cnt[b[i]] = 0;
			}
		} else if (tipo[i] == 'K') {
			int lo = 1;
			int hi = t;
			int k = val[i];
			if (query(n) < k) {
				cout << "invalid\n";
				continue;
			}
			//cout << query(n) << " ";
			int r = hi;
			while (lo <= hi) {
				int m = (lo + hi) >> 1;
				if (query(m) >= k) {
					r = m;
					hi = m - 1;
				} else {
					lo = m + 1;
				}
			}
			cout << a[r - 1] << "\n";
		} else if (tipo[i] == 'C') {
			cout << query(b[i] - 1) << "\n";
		}
		//cout << "t " << i << " " << query(n) << "\n";
	}
}
