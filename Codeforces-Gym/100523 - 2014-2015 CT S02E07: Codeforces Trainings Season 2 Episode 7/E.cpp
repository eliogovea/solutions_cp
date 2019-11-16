// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523E

#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
const int INF = 1e9 + 7;

int n, m, d, ll;
int x[N];

struct data {
	int mn;
	int freq;
	data() {
		mn = INF;
		freq = 0;
	}
	data(int _mn, int _freq) {
        mn = _mn;
        freq = _freq;
	}
};

data operator + (const data &a, const data &b) {
	if (a.mn < b.mn) {
		return a;
	}
	if (b.mn < a.mn) {
		return b;
	}
	return data(a.mn, a.freq + b.freq);
}

data st[4 * N];

int lazy[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
		st[x].mn = 0;
		st[x].freq = 1;
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		st[x] = st[2 * x] + st[2 * x + 1];
	}
}

void push(int x, int l, int r) {
	if (lazy[x] != 0) {
		st[x].mn += lazy[x];
		if (l != r) {
			lazy[2 * x] += lazy[x];
			lazy[2 * x + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}

void update(int x, int l, int r, int ul, int ur, int val) {
	push(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
		lazy[x] += val;
		push(x, l, r);
	} else {
		int mid = (l + r) >> 1;
		update(2 * x, l, mid, ul, ur, val);
		update(2 * x + 1, mid + 1, r, ul, ur, val);
		st[x] = st[2 * x] + st[2 * x + 1];
	}
}

void update(int center, int val) {\
	int l = lower_bound(x, x + n, center - ll) - x;
	int r = upper_bound(x, x + n, center + ll) - x - 1;
	if (r < l) {
		return;
	}
	update(1, 1, n, l + 1, r + 1, val);
}

data query(int x, int l, int r, int ql, int qr) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return data();
	}
	if (l >= ql && r <= qr) {
		return st[x];
	}
	int mid = (l + r) >> 1;
	data q1 = query(2 * x, l, mid, ql, qr);
	data q2 = query(2 * x + 1, mid + 1, r, ql, qr);
	return q1 + q2;
}

int query() {
	data res = query(1, 1, n, 1, n);
	if (res.mn != 0) {
		return n;
	}
	return n - res.freq;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> m >> d >> ll;
	for (int i = 1; i < n; i++) {
		cin >> x[i];
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int pos;
		cin >> pos;
		update(pos, 1);
	}
	cout << query() << "\n";
	for (int i = 0; i < d; i++) {
		int p, r;
		cin >> p >> r;
		update(p, -1);
		update(r, 1);
		cout << query() << "\n";
	}
}
