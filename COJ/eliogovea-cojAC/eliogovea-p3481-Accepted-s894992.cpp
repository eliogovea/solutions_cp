#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

const int MOD = 1000000007;

int n;
int a[N];

struct ST {
	int n;
	vector <int> t;
	ST() {}
	ST(int _n) {
		n = _n;
		t.resize(4 * n);
	}
	void update(int x, int l, int r, int p, int v) {
		if (p > r || p < l) return;
		if (l == r) {
			t[x] = v;
		} else {
			int m = (l + r) >> 1;
			update(2 * x, l, m, p, v);
			update(2 * x + 1, m + 1, r, p, v);
			t[x] = max(t[2 * x], t[2 * x + 1]);
		}
	}
	int query(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return t[x];
		int m = (l + r) >> 1;
		int q1 = query(2 * x, l, m, ql, qr);
		int q2 = query(2 * x + 1, m + 1, r, ql, qr);
		return max(q1, q2);
	}
};

const int A = 100;

bool criba[A + 5];

vector <int> p;
int pos[A];

vector <ST> t;

inline int mul(int a, int b) {
    return (long long)a * b % MOD;
}

inline long long power(long long x, int n) {
	long long res = 1;
	while (n) {
		if (n & 1) {
            res = mul(res, x);
		}
        x = mul(x, x);
		n >>= 1;
	}
	return res;
}

int q;
char ch;
int x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= A; i++) {
		if (!criba[i]) {
			pos[i] = p.size();
			p.push_back(i);
			for (int j = i + i; j <= A; j += i) {
				criba[j] = true;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < p.size(); i++) {
		t.push_back(ST(n));
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 0; p[j] * p[j] <= x; j++) {
			if (x % p[j] == 0) {
				int cnt = 0;
				while (x % p[j] == 0) {
					cnt++;
					x /= p[j];
				}
				t[j].update(1, 1, n, i, cnt);
			}
		}
		if (x > 1) {
			t[pos[x]].update(1, 1, n, i, 1);
		}
	}
	cin >> q;
	while (q--) {
		cin >> ch >> x >> y;
		if (ch == 'U') {
			for (int i = 0; i < p.size(); i++) {
				t[i].update(1, 1, n, x, 0);
			}
			for (int i = 0; p[i] * p[i] <= y; i++) {
				if (y % p[i] == 0) {
					int cnt = 0;
					while (y % p[i] == 0) {
						y /= p[i];
						cnt++;
					}
					t[i].update(1, 1, n, x, cnt);
				}
			}
			if (y > 1) {
				t[pos[y]].update(1, 1, n, x, 1);
			}
		} else {
			int ans = 1;
			for (int i = 0; i < p.size(); i++) {
				int mx = t[i].query(1, 1, n, x, y);
				ans = mul(ans, power(p[i], mx));
			}
			cout << ans << "\n";
		}
	}
}
