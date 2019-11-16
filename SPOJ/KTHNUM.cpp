#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100005;
 
int n, q;
int a[N], b[N];
vector<int> T[4 * N];
 
void build(int x, int l, int r) {
	if (l == r) {
		T[x] = vector<int>(1, a[l]);
	} else {
		int m = (l + r) >> 1;
		build(2 * x, l, m);
		build(2 * x + 1, m + 1, r);
		int pl = 0, pr = 0;
		while (pl < T[2 * x].size() && pr < T[2 * x + 1].size()) {
			if (T[2 * x][pl] < T[2 * x + 1][pr]) {
				T[x].push_back(T[2 * x][pl++]);
			} else {
				T[x].push_back(T[2 * x + 1][pr++]);
			}
		}
		while (pl < T[2 * x].size()) {
			T[x].push_back(T[2 * x][pl++]);
		}
		while (pr < T[2 * x + 1].size()) {
			T[x].push_back(T[2 * x + 1][pr++]);
		}
	}
}
 
int query(int x, int l, int r, int ql, int qr, int v) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return upper_bound(T[x].begin(), T[x].end(), v) - T[x].begin();
	}
	int m = (l + r) >> 1;
	int q1 = query(2 * x, l, m, ql, qr, v);
	int q2 = query(2 * x + 1, m + 1, r, ql, qr, v);
	return q1 + q2;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		int lo = -1e9, hi = 1e9;
		int ans = hi;
		int mid, val;
		//O(logN * logN * logN);
		while (lo <= hi) {
			mid = (lo + hi) >> 1;
			val = query(1, 1, n, x, y, mid);
			if (val >= z) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << ans << "\n";
	}
} 
