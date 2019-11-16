#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n;
int a[N + 5];
int ans[N + 5];

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
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = n - 1 - i - query(a[i]);
		update(a[i], 1);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i + 1 < n) {
			cout << " ";
		}
	}
	cout << "\n";
}
