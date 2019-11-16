#include <bits/stdc++.h>

using namespace std;

const int N = 250 * 1000 + 10;
const int INF = 1e9;

int n, m, k;
pair <int, int> v[N];
int kk[N];

int val[N];

int mx[4 * N];
int mn[4 * N];

int add[4 * N];

vector <int> ins[N];
vector <int> rem[N];

void build(int x, int l, int r) {
	mx[x] = 0;
	mn[x] = 0;
	add[x] = 0;
	if (l != r) {
		int m = (l + r) >> 1;
		build(2 * x, l, m);
		build(2 * x + 1, m + 1, r);
	}
}

inline void push(int x, int l, int r) {
	if (add[x] > 0) {
		mx[x] += add[x];
		mn[x] += add[x];
		if (l != r) {
			add[2 * x] += add[x];
			add[2 * x + 1] += add[x];
		}
		add[x] = 0;
	}
}

inline void update(int x, int l, int r, int ul, int ur) {
	push(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (ul <= l && r <= ur) {
		add[x]++;
		push(x, l, r);
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, ul, ur);
		update(2 * x + 1, m + 1, r, ul, ur);
		mx[x] = max(mx[2 * x], mx[2 * x + 1]);
		mn[x] = min(mn[2 * x], mn[2 * x + 1]);
	}
}

void query(int x, int l, int r, int ql, int qr, int & _mx, int & _mn) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return;
	}
	if (ql <= l && r <= qr) {
		_mx = max(_mx, mx[x]);
		_mn = min(_mn, mn[x]);
	} else {
		int m = (l + r) >> 1;
		query(2 * x, l, m, ql, qr, _mx, _mn);
		query(2 * x + 1, m + 1, r, ql, qr, _mx, _mn);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	for (int i = 0; i < k; i++) {
		cin >> kk[i];
		kk[i]--;
	}

	sort(v, v + n);

	build(1, 0, n - 1);

	for (int id = 0; id < n; id++) {
		int x = v[id].first;
		int i = v[id].second;
		int _mx = -INF;
		int _mn = INF;

		query(1, 0, n - 1, max(0, i - m + 1), min(i, n - m), _mx, _mn);

		ins[_mn].push_back(x);
		rem[_mx].push_back(x);

		update(1, 0, n - 1, max(0, i - m + 1), min(i, n - m));
	}


	set <int> active;
	for (int i = 0; i < m; i++) {
		for (auto x : ins[i]) {
			active.insert(x);
		}
		val[i] = *active.rbegin();
		for (auto x : rem[i]) {
			active.erase(active.find(x));
		}

	}

	for (int i = 0; i < k; i++) {
		cout << val[kk[i]];
		if (i + 1 < k) {
			cout << " ";
		}
	}
	cout << "\n";
}
