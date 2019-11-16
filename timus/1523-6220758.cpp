// Problem: pace=1&num=1523
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9;

int n, k;
int a[20005];
int bit[15][20005];

void update(int id, int p, int v) {
	while (p <= n) {
		bit[id][p] += v;
		bit[id][p] %= mod;
		p += p & -p;
	}
}

int query(int id, int p) {
	int res = 0;
	while (p > 0) {
		res += bit[id][p];
		res %= mod;
		p -= p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = k - 1; j > 0; j--) {
			int tmp = (query(j - 1, n) - query(j - 1, a[i] - 1) + mod) % mod;
			update(j, a[i], tmp);
		}
		update(0, a[i], 1);
	}
	cout << query(k - 1, n) << "\n";
}
