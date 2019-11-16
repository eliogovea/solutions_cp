#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void gen(const vector <LL> &values, int pos, LL d1, LL d2, vector <pair <LL, LL> > &points) {
	if (pos == values.size()) {
		points.push_back(make_pair(d1, d2));
	} else {
		gen(values, pos + 1, d1 + values[pos], d2, points);
		gen(values, pos + 1, d1 - values[pos], d2 + values[pos], points);
		gen(values, pos + 1, d1, d2 - values[pos], points);
	}
}

const LL INF = 1000000000000000000LL;

struct segmentTree {
	int n;
	vector <LL> tree;
	segmentTree() {}
	segmentTree(int _n) {
		n = _n;
		tree.resize(4 * n, INF);
	}
	void update(int x, int l, int r, int p, LL v) {
		if (p < l || r < p) {
			return;
		}
		if (l == r) {
			tree[x] = min(tree[x], v);
		} else {
			int mid = (l + r) >> 1;
			update(2 * x, l, mid, p, v);
			update(2 * x + 1, mid + 1, r, p, v);
			tree[x] = min(tree[2 * x], tree[2 * x + 1]);
		}
	}
	void update(int p, LL v) {
		update(1, 1, n, p, v);
	}
	LL query(int x, int l, int r, int ql, int qr) {
		if (l > qr || r < ql) {
			return INF;
		}
		if (l >= ql && r <= qr) {
			return tree[x];
		}
		int mid = (l + r) >> 1;
		LL q1 = query(2 * x, l, mid, ql, qr);
		LL q2 = query(2 * x + 1, mid + 1, r, ql, qr);
		return min(q1, q2);
	}
	LL query(int l, int r) {
		return query(1, 1, n, l, r);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
	int n;
	cin >> n;
	vector <LL> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	int n1 = n / 2;
	int n2 = n - n1;
	vector <LL> values1(n1);
	for (int i = 0; i < n1; i++) {
		values1[i] = values[i];
	}
	vector <LL> values2(n2);
	for (int i = 0; i < n2; i++) {
		values2[i] = values[n1 + i];
	}
	vector <pair <LL, LL> > points1;
	gen(values1, 0, 0, 0, points1);
	vector <pair <LL, LL> > points2;
	gen(values2, 0, 0, 0, points2);
	for (int i = 0; i < points1.size(); i++) {
		points1[i].first = -points1[i].first;
		points1[i].second = -points1[i].second;
	}
	sort(points1.begin(), points1.end());
	sort(points2.begin(), points2.end());
	vector <LL> y(points1.size() + points2.size());
	for (int i = 0; i < points1.size(); i++) {
		y[i] = points1[i].second;
	}
	for (int i = 0; i < points2.size(); i++) {
		y[points1.size() + i] = points2[i].second;
	}
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	segmentTree st(y.size());
	LL ans = INF;
	for (int i = points1.size() - 1, j = points2.size() - 1; i >= 0; i--) {
		while (j >= 0 && points2[j].first >= points1[i].first) {
			int posY = lower_bound(y.begin(), y.end(), points2[j].second) - y.begin() + 1;
			st.update(posY, points2[j].first + points2[j].second);
			j--;
		}
		int posY = lower_bound(y.begin(), y.end(), points1[i].second) - y.begin() + 1;
		LL v = -points1[i].first + -points1[i].second + st.query(posY, y.size());
		ans = min(ans, v);
	}
	cout << ans << "\n";
}
