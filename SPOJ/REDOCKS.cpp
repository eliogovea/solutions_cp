#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 250005;
 
int n, m;
string s;
int a, b;
 
struct data {
	int v[11];
	int lazy;
	data() {}
	void update() {
		int aux[11];
		for (int i = 0; i < 10; i++) {
			aux[i] = v[i];
		}
		for (int i = 0; i < 10; i++) {
			v[(i + lazy) % 10] = aux[i];
		}
		lazy = 0;
	}
	int get() {
	    assert(lazy == 0);
		int res = 0;
		for (int i = 1; i < 10; i++) {
			res += i * v[i];
		}
		return res;
	}
} t[4 * N];
 
data merge(const data &a, const data &b) {
	data res;
	res.lazy = 0;
	for (int i = 0; i < 10; i++) {
		res.v[i] = a.v[i] + b.v[i];
	}
	return res;
}
 
void build(int x, int l, int r) {
	if (l == r) {
        t[x].lazy = 0;
        for (int i = 0; i < 10; i++) {
            t[x].v[i] = (s[l - 1] - '0' == i);
        }
		t[x].v[s[l - 1] - '0'] = 1;
	} else {
		int mid = (l + r) >> 1;
		build(x + x, l, mid);
		build(x + x + 1, mid + 1, r);
		t[x] = merge(t[x + x], t[x + x + 1]);
	}
}
 
void push(int x, int l, int r) {
	int lazy = t[x].lazy;
	if (lazy) {
		t[x].update();
		if (l != r) {
			t[x + x].lazy = (t[x + x].lazy + lazy) % 10;
			t[x + x + 1].lazy = (t[x + x + 1].lazy + lazy) % 10;
		}
	}
}
 
void update(int x, int l, int r, int ul, int ur) {
	push(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
        assert(t[x].lazy == 0);
		t[x].lazy = 1;
		push(x, l, r);
	} else {
		int mid = (l + r) >> 1;
		update(x + x, l, mid, ul, ur);
		update(x + x + 1, mid + 1, r, ul, ur);
		t[x] = merge(t[x + x], t[x + x + 1]);
	}
}
 
int query(int x, int l, int r, int ql, int qr) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return t[x].get();
	}
	int mid = (l + r) >> 1;
	int q1 = query(x + x, l, mid, ql, qr);
	int q2 = query(x + x + 1, mid + 1, r, ql, qr);
	return q1 + q2;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	build(1, 1, n);
	while (m--) {
		cin >> a >> b;
		cout << query(1, 1, n, a, b) << "\n";
		update(1, 1, n, a, b);
	}
}
