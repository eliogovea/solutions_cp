// 2014 Benelux Algorithm Programming Contest (BAPC 14), 2014-2015 CT S02E08: Codeforces Trainings Season 2 Episode 8
// 100526E

#include <bits/stdc++.h>

using namespace std;

struct ob {
	int r1, r2, r3;
};

bool operator < (const ob &a, const ob &b) {
	return a.r1 < b.r1;
}



struct BIT {
	int n;
	vector <int> v;
	BIT() {}
	BIT(int _n) {
		n = _n;
		v.resize(n + 5);
	}
	void update(int p, int val) {
		while (p <= n) {
            //cout << p << "\n";
			v[p] += val;
			p += p & -p;
		}
	}
	int query(int p) {
		int res = 0;
		while (p > 0) {
			res += v[p];
			p -= p & -p;
		}
		return res;
	}
};

struct data {
	int n;
	BIT bit;
	vector <int> y;
};

data operator + (const data &a, const data &b) {
	vector <int> v;
	v.resize(a.n + b.n);
	int pa = 0;
	int pb = 0;
	int pv = 0;
	while (pa < a.n && pb < b.n) {
		if (a.y[pa] < b.y[pb]) {
			v[pv++] = a.y[pa++];
		} else {
			v[pv++] = b.y[pb++];
		}
	}
	while (pa < a.n) {
		v[pv++] = a.y[pa++];
	}
	while (pb < b.n) {
		v[pv++] = b.y[pb++];
	}
	return (data) {a.n + b.n, BIT(a.n + b.n), v};
}

const int N = 100005;

int n;
ob arr[N];

data ST[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
        ST[x].n = 1;
		ST[x].bit = BIT(1);
		ST[x].y = vector <int> (1, arr[l].r3);
	} else {
		int mid = (l + r) >> 1;
		int ls = x + x, rs = ls + 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		ST[x] = ST[ls] + ST[rs];
	}

}

bool cmp2(const ob &a, const ob &b) {
    return a.r2 < b.r2;
}

void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	int pos = upper_bound(ST[x].y.begin(), ST[x].y.end(), v) - ST[x].y.begin();
	ST[x].bit.update(pos, 1);
	if (l != r) {
		int mid = (l + r) >> 1;
		int ls = x + x, rs = ls + 1;
		update(ls, l, mid, p, v);
		update(rs, mid + 1, r, p, v);
	}
}

bool query(int x, int l, int r, int ql, int qr, int Y) {
	if (l > qr || r < ql) {
		return false;
	}
	if (l >= ql && r <= qr) {
		int pos = upper_bound(ST[x].y.begin(), ST[x].y.end(), Y) - ST[x].y.begin();
		int sum = ST[x].bit.query(pos);
		return (sum > 0);
	}
	int mid = (l + r) >> 1;
	int ls = x + x, rs = ls + 1;
	bool q1 = query(ls, l, mid, ql, qr, Y);
	bool q2 = query(rs, mid + 1, r, ql, qr, Y);
	return (q1 | q2);
}

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].r1 >> arr[i].r2 >> arr[i].r3;
		}
		sort(arr + 1, arr + n + 1, cmp2);
		build(1, 1, n);
		sort(arr + 1, arr + n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			bool ex = query(1, 1, n, 1, arr[i].r2 - 1, arr[i].r3 - 1);
			if (ex) ans++;
			update(1, 1, n, arr[i].r2, arr[i].r3);
		}
		cout << n - ans << "\n";
	}
}
