#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200005;

const ll inf = 1000000000000000000LL;

int n;
ll p;

int t[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
		t[x] = 1;
	} else {
		int m = (l + r) >> 1;
		build(2 * x, l, m);
		build(2 * x + 1, m + 1, r);
		t[x] = t[2 * x] + t[2 * x + 1];
	}
}

void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		t[x] = v;
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, p, v);
		update(2 * x + 1, m + 1, r, p, v);
		t[x] = t[2 * x] + t[2 * x + 1];
	}
}

int find_kth(int k) {
	int x = 1;
	int l = 1;
	int r = n;
	while (l != r) {
		if (t[2 * x] >= k) {
			x = 2 * x;
			r = (l + r) / 2;
		} else {
			k -= t[2 * x];
			x = 2 * x + 1;
			l = (l + r) / 2 + 1;
		}
	}
	return l;
}

vector<ll> f;
int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	build(1, 1, n);
	f.push_back(1);
	while (f.size() < n && f.back() <= inf / f.size()) {
		f.push_back(1LL * f.size() * f.back());
	}
	p--;
	for (int i = 1; i <= n; i++) {
		int cnt = n - i;
		if (cnt > f.size() - 1) {
			ans[i] = i;
			update(1, 1, n, i, 0);
			continue;
		}
		ll k = p / f[cnt];
		int v = find_kth(k + 1);
		ans[i] = v;
		update(1, 1, n, v, 0);
		p -= k * f[cnt];
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
	}
}
