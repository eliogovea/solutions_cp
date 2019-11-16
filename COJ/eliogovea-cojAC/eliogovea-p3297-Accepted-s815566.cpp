#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, k;

int bit[N];

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

int ans[N];

int solve() {
	for (int i = 1; i <= n; i++) {
			bit[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}
	int cur = 1;
	int res;
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
							res = p1;
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
				res = p1;
				update(p1, -1);
				cur = p2;
				//cout << p1 << " " << p2 << "\n";
		}
		dir ^= 1;
		//cout << ans << "\n";
	}
	ans[k] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}
		if (k == 1) {
			if (n == 1) {
				cout << "1\n";
			} else {
				cout << (n + 1) / 2 + 1 << "\n";
			}
			continue;
		}
		if (k == 2) {
			if (n == 2) {
				cout << "1\n";
			} else {
				cout << n / 2 + 2 << "\n";
			}
			continue;
		}
		if (ans[k] != 0) {
			if ((n - k) & 1) {
				cout << k + 1 - ans[k] << "\n";
			} else {
				cout << ans[k] << "\n";
			}
			continue;
		}
		int v = n;
		n = k;
		int x = solve();
		if ((v - k) & 1) {
			cout << k + 1 - ans[k] << "\n";
		} else {
			cout << ans[k] << "\n";
		}
	}
}
