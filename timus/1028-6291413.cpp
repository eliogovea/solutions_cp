// Problem: pace=1&num=1028
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 32005;

int n;
int x[N], y[N];

int ans[N];

int bit[N];

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
		p -=  p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i]++;
		int tmp = query(x[i]);
		ans[tmp]++;
		update(x[i], 1);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}
