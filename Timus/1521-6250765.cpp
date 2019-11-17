// Problem: pace=1&num=1521
// Verdict: Accepted

#include <bits/stdc++.h>

#define ver(x) cout << #x << " " << x << "\n";

using namespace std;

const int N = 100005;

int n, k;

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

int ans[N];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}
	int last = 0; // ultima posicio que elimine
	for (int i = 1; i <= n; i++) {
		int t = n + 1 - i; // total que queda debe
		int x = query(last);
		int y;
		int z = (k % t);
		if (x + z <= t) {
			y = x + z;
      if (y == 0) {
        y = t;
      }
		} else {
			y = z - (t - x);
			if (y == 0) {
        y = t;
			}
		}
		int lo = 1;
		int hi = n;
		int pos = -1;
		while (lo <= hi) {
			int m = (lo + hi) >> 1;
			//cout << m << " " << query(m) << "\n";
			if (query(m) >= y) {
				pos = m;
				hi = m - 1;
			} else {
				lo = m + 1;
			}
		}
		ans[i] = pos;
		update(pos, -1);
		last = pos;
		//ver(i); ver(t); ver(x); ver(y); ver(z); ver(pos);
		//cout << "-------------------------\n";
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
		if (i + 1 <= n) {
			cout << " ";
		}
	}
	cout << "\n";
}
