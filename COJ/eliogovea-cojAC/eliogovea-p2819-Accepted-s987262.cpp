#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

const int Size = 2;
struct matrix {
	int n;
	int v[Size + 1][Size + 1];
	matrix(int v0 = 0) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				v[i][j] = 0;
			}
			v[i][i] = v0;
		}
	}
	matrix(int a, int b, int c, int d) {
		v[0][0] = a;
		v[0][1] = b;
		v[1][0] = c;
		v[1][1] = d;
	}
	int * operator [] (const int x) {
		return v[x];
	}
	const int * operator [] (const int x) const {
		return v[x];
	}
};

matrix operator + (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			res[i][j] = a[i][j];
			add(res[i][j], b[i][j]);
		}
	}
	return res;
}

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			for (int k = 0; k < Size; k++) {
				add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return res;
}

matrix power(matrix x, long long n) {
	matrix res(1);
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}

const int N = 100005;
const matrix F(1, 1, 1, 0);

int a[N];

matrix st[4 * N];
bool updated[4 * N];
matrix lazy[4 * N];

void build(int x, int l, int r) {
	updated[x] = true;
	lazy[x] = matrix(1);
	if (l == r) {
		st[x] = power(F, a[l]);
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		st[x] = st[2 * x] + st[2 * x + 1];
	}
}

inline void push(int x, int l, int r) {
	if (!updated[x]) {
		st[x] = st[x] * lazy[x];
		if (l != r) {
			updated[2 * x] = false;
			lazy[2 * x] = lazy[2 * x] * lazy[x];
			updated[2 * x + 1] = false;
			lazy[2 * x + 1] = lazy[2 * x + 1] * lazy[x];
		}
		updated[x] = true;
		lazy[x] = matrix(1);
	}
}

void update(int x, int l, int r, int ul, int ur, long long v) {
	push(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
        updated[x] = false;
		lazy[x] = lazy[x] * power(F, v);
		push(x, l, r);
	} else {
		int mid = (l + r) >> 1;
		update(2 * x, l, mid, ul, ur, v);
		update(2 * x + 1, mid + 1, r, ul, ur, v);
		st[x] = st[2 * x] + st[2 * x + 1];
	}
}

matrix query(int x, int l, int r, int ql, int qr) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return matrix(0);
	}
	if (l >= ql && r <= qr) {
		return st[x];
	}
	int mid = (l + r) >> 1;
	matrix q1 = query(2 * x, l, mid, ql, qr);
	matrix q2 = query(2 * x + 1, mid + 1, r, ql, qr);
	return q1 + q2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		build(1, 1, n);
		int m;
		cin >> m;
		while (m--) {
			int type;
			cin >> type;
			if (type == 1) {
				int l, r;
				cin >> l >> r;
				matrix M = query(1, 1, n, l, r);
				int ans = 0;
				add(ans, M[1][0]);
				add(ans, M[1][1]);
				cout << ans << "\n";
			} else {
				int l, r;
				long long v;
				cin >> l >> r >> v;
				update(1, 1, n, l, r, v);
			}
		}
	}
}
