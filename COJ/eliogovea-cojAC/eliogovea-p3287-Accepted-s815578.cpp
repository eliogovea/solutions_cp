#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int bit[N];

int n, k;

inline void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}

inline int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

inline int f(int x) {
    int lo = 1;
    int hi = n;
    int res = -1;
    while (lo <= hi) {
        int m = (lo + hi) >> 1;
        if (query(m) >= x) {
            res = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
            bit[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			update(i, 1);
		}
		int cur = 1;
		int ans;
		int dir = 1;
		for (int i = 1; i <= n; i++) {
			int x;
			int cnt = query(cur);
			//cout << "cnt = " << cnt << "\n";
			int tot = n + 1 - i;
			int kk = k % tot;
			if (dir == 1) {
                if (cnt - 1 + kk <= tot) {
                    x = cnt - 1 + kk;
                } else {
                    x = kk - (tot - (cnt - 1));
                }
                if (x == 0) {
                    x = tot;
                }
                //cout << "x = " << x << "\n";
                int p1 = f(x);
                int p2 = f(x != tot ? x + 1 : 1);
                update(p1, -1);
                ans = p1;
                cur = p2;
                //cout << p1 << " " << p2 << "\n";
			} else {
			    if (cnt >= kk) {
                    x = cnt - kk + 1;
			    } else {
                    x = tot - (kk - cnt) + 1;
			    }
			    if (x == tot + 1) {
                    x = 1;
			    }
			    int p1 = f(x);
			    int p2 = f(x != 1 ? x - 1 : tot);
			    ans = p1;
			    update(p1, -1);
			    cur = p2;
			    //cout << p1 << " " << p2 << "\n";
			}
			dir ^= 1;
			//cout << ans << "\n";
		}
		cout << ans << "\n";
	}
}
