#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 100005;

int n;
int cap[N], lev[N], next[N];
int q;
int t, a, b;

int find_next(int id) {
	if (next[id] != id) {
		next[id] = find_next(next[id]);
	}
	return next[id];
}

void func(int id, int vol) {
	if (id == n + 1) {
		return;
	}
	if (lev[id] + vol <= cap[id]) {
		lev[id] += vol;
		return;
	}
	vol = vol - (cap[id] - lev[id]);
	lev[id] = cap[id];
	next[id] = find_next(id + 1);
	func(next[id], vol);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cap[i];
		lev[i] = 0;
		next[i] = i;
	}
	next[n + 1] = n + 1;
	cin >> q;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> a;
			cout << lev[a] << "\n";
		} else {
			cin >> a >> b;
			func(a, b);
		}
	}
}
