#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct data {
	int size;
	int val[15];
	data() {
		size = 0;
	}
};

data merge(const data &a, const data &b) {
	data res;
	res.size = 0;
	int pa = 0;
	int pb = 0;
	while (pa < a.size && pb < b.size) {
		if (a.val[pa] < b.val[pb]) {
			res.val[res.size++] = a.val[pa++];
			if (res.size == 10) {
				return res;
			}
		} else {
			res.val[res.size++] = b.val[pb++];
			if (res.size == 10) {
				return res;
			}
		}
	}
	if (res.size == 10) {
		return res;
	}
	while (pa < a.size) {
		res.val[res.size++] = a.val[pa++];
		if (res.size == 10) {
			return res;
		}
	}
	while (pb < b.size) {
		res.val[res.size++] = b.val[pb++];
		if (res.size == 10) {
			return res;
		}
	}
	return res;
}

int n, m, q;
data a[N];
data t[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
		t[x] = a[l];
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		t[x] = merge(t[2 * x], t[2 * x + 1]);
	}
}

data query(int x, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return data();
	}
	if (l >= ql && r <= qr) {
		return t[x];
	}
	int mid = (l + r) >> 1;
	data q1 = query(2 * x, l, mid, ql, qr);
	data q2 = query(2 * x + 1, mid + 1, r, ql, qr);
	return merge(q1, q2);
}

int v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> v[j];
		}
		sort(v, v + k);
		a[i].size = min(10, k);
		for (int j = 0; j < a[i].size; j++) {
			a[i].val[j] = v[j];
		}
	}
	build(1, 1, m);
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
            swap(a, b);
		}
		data ans = query(1, 1, m, a, b);
		for (int i = 0; i < ans.size; i++) {
			cout << ans.val[i];
			if (i + 1 < ans.size) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
