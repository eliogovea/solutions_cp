// Problem: pace=1&num=1090
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n, k;
int line[10005];

int bit[10005];

void clear() {
	for (int i = 1; i <= n; i++) {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> k;
	int mx = -1;
	int id = -1;
	for (int i = 1; i <= k; i++) {
		clear();
		int t = 0;
		for (int j = 1; j <= n; j++) {
			cin >> line[j];
			line[j] = n + 1 - line[j]; // 1 es el mayor
			t += query(line[j]);
			update(line[j], 1);
		}
		if (t > mx) {
			mx = t;
			id = i;
		}
	}
	cout << id << "\n";
}
