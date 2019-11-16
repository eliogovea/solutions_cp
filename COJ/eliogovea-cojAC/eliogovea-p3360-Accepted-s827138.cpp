#include <bits/stdc++.h>

using namespace std;

struct event {
	int val, pos, id;
	int st, en;
};

bool operator < (const event &a, const event &b) {
	if (a.val != b.val) {
		return a.val > b.val;
	}
	return a.id > b.id;
}

int n, q;
int h[1005];
vector<event> E;
event e;

int bit[1005];

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

int ans[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		e.val = h[i];
		e.pos = i;
		e.id = 0;
		E.push_back(e);
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		e.val	= max(h[x], h[y]);
		e.pos = i;
		e.st = x;
		e.en = y;
		e.id = 1;
		E.push_back(e);
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		if (E[i].id == 0) {
			update(E[i].pos, 1);
		} else {
			int tmp = query(E[i].en) - query(E[i].st);
			ans[E[i].pos] = tmp;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}
