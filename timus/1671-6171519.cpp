// Problem: pace=1&num=1671
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

// Timus - 1671. Anansi's Cobweb

const int N = 100005;

int n, m, u[N], v[N], q, qu[N], mark[N], ans[N];

int p[N];

int find(int x) {
	if (x != p[x]) {
		p[x] = find(p[x]);
	}
	return p[x];
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	p[x] = y;
}

int main() {
	//freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> qu[i];
		mark[qu[i]] = true;
	}
	for (int i = 1; i <= m; i++) {
		if (!mark[i]) {
			join(u[i], v[i]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) {
			cnt++;
		}
	}
	for (int i = q; i > 0; i--) {
		ans[i] = cnt;
		if (find(u[qu[i]]) != find(v[qu[i]])) {
			cnt--;
		}
		join(u[qu[i]], v[qu[i]]);
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
}