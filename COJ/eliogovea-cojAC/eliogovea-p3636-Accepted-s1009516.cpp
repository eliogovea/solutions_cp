#include <bits/stdc++.h>

using namespace std;

struct data {
	int n;
	vector <int> values;
	vector <int> bit;
	data() {}
	data(vector <int> &_values) {
		n = _values.size();
		values = _values;
		bit = vector <int> (n + 1, 0);
	}
	int getPos(int x) {
		int pos = lower_bound(values.begin(), values.end(), x) - values.begin();
		if (pos == (int)values.size()) {
			return pos;
		}
		if (values[pos] == x) {
			return pos + 1;
		}
		return pos;
	}
	void bitUpdate(int p, int v) {
		while (p <= n) {
			bit[p] += v;
			p += p & -p;
		}
	}
	int bitQuery(int p) {
		int res = 0;
		while (p > 0) {
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
	void update(int x, int v) {
		x = getPos(x);
		bitUpdate(x, v);
	}
	int query(int x) {
		x = getPos(x);
		return bitQuery(x);
	}
};

data operator + (const data &a, const data &b) {
	data res;
	res.values.resize(a.n + b.n);
	int pa = 0;
	int pb = 0;
	int p = 0;
	while (pa < a.n && pb < b.n) {
		if (a.values[pa] <= b.values[pb]) {
			res.values[p++] = a.values[pa++];
		} else {
			res.values[p++] = b.values[pb++];
		}
	}
	while (pa < a.n) {
		res.values[p++] = a.values[pa++];
	}
	while (pb < b.n) {
		res.values[p++] = b.values[pb++];
	}
	res.values.erase(unique(res.values.begin(), res.values.end()), res.values.end());
	res.n = res.values.size();
	res.bit = vector <int> (res.n + 1, 0);
	return res;
}

const int N = 600002;

data st[4 * N];

int n, m;
int bones[N];
int q[5][2000002];
vector <int> v[N];

void build(int x, int l, int r) {
	if (l == r) {
		st[x] = data(v[l]);
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		st[x] = st[2 * x] + st[2 * x + 1];
	}
}

void update(int x, int l, int r, int p, int val, int add) {
	st[x].update(val, add);
	if (l != r) {
		int mid = (l + r) >> 1;
		if (p <= mid) {
			update(2 * x, l, mid, p, val, add);
		} else {
			update(2 * x + 1, mid + 1, r, p, val, add);
		}
	}
}

int query(int x, int l, int r, int ql, int qr, int val) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return st[x].query(val);
	}
	int mid = (l + r) >> 1;
	int q1 = query(2 * x, l, mid, ql, qr, val);
	int q2 = query(2 * x + 1, mid + 1, r, ql, qr, val);
	return q1 + q2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			v[i].clear();
			bones[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			cin >> q[0][i] >> q[1][i] >> q[2][i];
			if (q[0][i] == 1) {
				cin >> q[3][i];
			}
			if (q[0][i] == 0) {
				v[q[1][i]].push_back(q[2][i]);
			}
		}
		for (int i = 0; i < n; i++) {
			sort(v[i].begin(), v[i].end());
			v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		}
		build(1, 0, n - 1);
		for (int i = 0; i < m; i++) {
			if (q[0][i] == 1) {
				cout << query(1, 0, n - 1, q[1][i], q[2][i], q[3][i]) << "\n";
			} else {
				if (bones[q[1][i]] != 0) {
					update(1, 0, n - 1, q[1][i], bones[q[1][i]], -1);
				}
				bones[q[1][i]] = q[2][i];
				update(1, 0, n - 1, q[1][i], q[2][i], 1);
			}
		}
	}
}
