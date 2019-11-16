#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

char op;
string sol;
int x, y;
int n, k, a[MAXN], T[MAXN << 2];

void build(int idx, int l, int r) {
	if (l == r) {
		if (a[l] > 0) T[idx] = 1;
		else if (a[l] == 0) T[idx] = 0;
		else T[idx] = -1;
	}
	else {
		int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
		build(L, l, mid);
		build(R, mid + 1, r);
		T[idx] = T[L] * T[R];
	}
}

void update(int idx, int l, int r, int pos, int val) {
	//cout << idx << ' ' << l << ' ' << r << '\n';
	if (l == r) {
		a[l] = val;
		if (a[l] > 0) T[idx] = 1;
		else if (a[l] == 0) T[idx] = 0;
		else T[idx] = -1;
	}
	else {
        int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
        if (pos <= mid) update(L, l, mid, pos, val);
        else update(R, mid + 1, r, pos, val);
        T[idx] = T[L] * T[R];
	}
}

int query(int idx, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 1;
	if (l >= ql && r <= qr) return T[idx];
	int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
	return query(L, l, mid, ql, qr) * query(R, mid + 1, r, ql, qr);
}

int main() {
	while (cin >> n >> k) {
        sol = "";
		for (int i = 1; i <= n; i++) cin >> a[i];
		build(1, 1, n);
		for (int i = 1; i <= k; i++) {
			cin >> op >> x >> y;
			if (op == 'C') update(1, 1, n, x, y);
			else {
				int aux = query(1, 1, n, x, y);
				if (aux > 0) sol += '+';
				else if (aux == 0) sol += '0';
				else sol += '-';
			}
		}
		cout << sol << '\n';
	}
}
