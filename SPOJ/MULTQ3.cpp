#include <bits/stdc++.h>
 
using namespace std;
 
struct node {
	int v[3];
	int lazy;
	node() {
		v[0] = v[1] = v[2] = 0;
		lazy = 0;
	}
	void update() {
		int aux[3];
		for (int i = 0; i < 3; i++) {
			aux[i] = v[i];
		}
		for (int i = 0; i < 3; i++) {
			v[(i + lazy) % 3] = aux[i];
		}
		lazy = 0;
	}
};
 
node operator + (const node &a, const node &b) {
	node res;
	for (int i = 0; i < 3; i++) {
		res.v[i] = a.v[i] + b.v[i];
	}
	res.lazy = 0;
	return res;
}
 
const int N = 100005;
 
node t[4 * N];
 
void build(int x, int l, int r) {
    if (l == r) {
        t[x].v[0] = 1;
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        t[x] = t[2 * x] + t[2 * x + 1];
    }
}
 
void propagate(int x, int l, int r) {
	int lazy = t[x].lazy;
	if (lazy) {
		t[x].update();
		if (l != r) {
			t[2 * x].lazy = (t[2 * x].lazy + lazy) % 3;
			t[2 * x + 1].lazy = (t[2 * x + 1].lazy + lazy) % 3;
		}
	}
}
 
void update(int x, int l, int r, int ul, int ur) {
	propagate(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
		t[x].lazy = (t[x].lazy + 1) % 3;
		propagate(x, l, r);
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, ul, ur);
		update(2 * x + 1, m + 1, r, ul, ur);
		t[x] = t[2 * x] + t[2 * x + 1];
	}
}
 
node query(int x, int l, int r, int ql, int qr) {
	propagate(x, l, r);
	if (l > qr || r < ql) {
		return node();
	}
	if (l >= ql && r <= qr) {
		return t[x];
	}
	int m = (l + r) >> 1;
	node q1 = query(2 * x, l, m, ql, qr);
	node q2 = query(2 * x + 1, m + 1, r, ql, qr);
	return q1 + q2;
}
 
int n, q, a, b, c;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	build(1, 1, n);
	while (q--) {
		cin >> a >> b >> c;
		if (a == 0) {
			update(1, 1, n, b + 1, c + 1);
		} else {
			cout << query(1, 1, n, b + 1, c + 1).v[0] << "\n";
		}
	}
}
