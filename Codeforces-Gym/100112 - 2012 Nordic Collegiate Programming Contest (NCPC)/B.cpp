// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112B

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
int a[100005], b[100005];

int bit[N];

void init() {
	for (int i = 0; i <= n; i++) {
		bit[i] = 0;
	}
}

void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}

int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int calc(int *a) {
	init();
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += query(a[i]);
		update(a[i], 1);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int va = calc(a) & 1;
	int vb = calc(b) & 1;
	if (va == vb) {
		cout << "Possible\n";
	} else {
		cout << "Impossible\n";
	}
}
