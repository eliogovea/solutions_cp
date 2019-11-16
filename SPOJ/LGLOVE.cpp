#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1000 * 1000 * 1000 + 7;
 
inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}
 
inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}
 
inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}
 
const int N = 300 * 1000 + 10;
 
int lp[N];
int cp[N];
int val[N];
 
const int SIZE = 100 * 1000 + 10;
 
int n, m;
int a[SIZE];
 
int maxVal[4 * SIZE];
int minVal[4 * SIZE];
 
int toAdd[4 * SIZE];
 
inline void build(int x, int l, int r) {
	toAdd[x] = 0;
	if (l == r) {
		maxVal[x] = minVal[x] = a[l];
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		minVal[x] = min(minVal[2 * x], minVal[2 * x + 1]);
		maxVal[x] = max(maxVal[2 * x], maxVal[2 * x + 1]);
	}
}
 
inline void push(int x, int l, int r) {
	if (toAdd[x] != 0) {
		minVal[x] += toAdd[x];
		maxVal[x] += toAdd[x];
		if (l != r) {
			int mid = (l + r) >> 1;
			toAdd[2 * x] += toAdd[x];
			toAdd[2 * x + 1] += toAdd[x];
		}
		toAdd[x] = 0;
	}
}
 
inline void update(int x, int l, int r, int ul, int ur, int v) {
	push(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (ul <= l && r <= ur) {
		toAdd[x] = v;
		push(x, l, r);
	} else {
		int mid = (l + r) >> 1;
		update(2 * x, l, mid, ul, ur, v);
		update(2 * x + 1, mid + 1, r, ul, ur, v);
		minVal[x] = min(minVal[2 * x], minVal[2 * x + 1]);
		maxVal[x] = max(maxVal[2 * x], maxVal[2 * x + 1]);
	}
}
 
const int INF = 1e8;
 
inline int getMin(int x, int l, int r, int ql, int qr) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return INF;
	}
	if (ql <= l && r <= qr) {
		return minVal[x];
	}
	int mid = (l + r) >> 1;
	int q1 = getMin(2 * x, l, mid, ql, qr);
	int q2 = getMin(2 * x + 1, mid + 1, r, ql, qr);
	return min(q1, q2);
}
 
inline int getMax(int x, int l, int r, int ql, int qr) {
	push(x, l, r);
	if (l > qr || r < ql) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return maxVal[x];
	}
	int mid = (l + r) >> 1;
	int q1 = getMax(2 * x, l, mid, ql, qr);
	int q2 = getMax(2 * x + 1, mid + 1, r, ql, qr);
	return max(q1, q2);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cp[0] = 0;
	cp[1] = 0;
	for (int i = 2; i < N; i++) {
		if (!cp[i]) {
			for (int j = i; j < N; j += i) {
				lp[j] = i;
				cp[j]++;
			}
		}
	}
 
	val[0] = 0;
	val[1] = 1;
	for (int i = 2; i < N; i++) {
		val[i] = val[i - 1];
		if (cp[i] == 1) {
			if (lp[i] != i) {
				val[i] = mul(val[i], power(i / lp[i], MOD - 2));
			}
			val[i] = mul(val[i], i);
		}
	}
 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	build(1, 0, n - 1);
 
	int a, b, c, d;
	while (m--) {
		cin >> a;
		if (a == 0) {
			cin >> b >> c >> d;
			update(1, 0, n - 1, b, c, d);
		} else if (a == 1) {
			cin >> b >> c;
			cout << val[getMax(1, 0, n - 1, b, c)] << "\n";
		} else {
			cin >> b >> c;
			cout << val[getMin(1, 0, n - 1, b, c)] << "\n";
		}
	}
}
 
/*
5 5
4 1 3 6 2
1 2 4
2 1 3
0 0 3 2
1 1 2
2 2 4
 
60
1
60
2
*/
