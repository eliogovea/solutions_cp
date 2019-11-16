#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n;
long long a[N + 5], b[N + 5];
int bit[N + 5];

void update(int p, int v) {
	while (p <= N) {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(b, b + n, a[i]) - b + 1;
		cout << query(a[i]) + 1;
		cout << "\n";
		update(a[i], 1);
	}
}
