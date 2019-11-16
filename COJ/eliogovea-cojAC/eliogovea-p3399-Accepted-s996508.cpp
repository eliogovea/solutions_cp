#include <bits/stdc++.h>

using namespace std;

struct segmentTree {
	int n;
	vector <bool> t;
	segmentTree() {}
	segmentTree(int _n) {
		n = _n;
		t = vector <bool> (4 * n, false);
	}
	inline void push(int x, int l, int r) {
		if (t[x]) {
			if (l != r) {
				t[2 * x] = true;
				t[2 * x + 1] = true;
			}
		}
	}
	void update(int x, int l, int r, int ul, int ur) {
		if (r < ul || ur < l) {
			return;
		}
		push(x, l, r);
		if (ul <= l && r <= ur) {
			t[x] = true;
			push(x, l, r);
		} else {
			int mid = (l + r) >> 1;
			update(2 * x, l, mid, ul, ur);
			update(2 * x + 1, mid + 1, r, ul, ur);
			t[x] = (t[2 * x] && t[2 * x + 1]);
		}
	}
	void update(int ul, int ur) {
		update(1, 1, n, ul, ur);
	}
	bool query(int x, int l, int r, int ql, int qr) {
		if (r < ql || qr < l) {
			return true;
		}
		push(x, l, r);
		if (ql <= l && r <= qr) {
			return t[x];
		}
		int mid = (l + r) >> 1;
		bool q1 = query(2 * x, l, mid, ql, qr);
		bool q2 = query(2 * x + 1, mid + 1, r, ql, qr);
		return (q1 && q2);
	}
	bool query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

void dfs(vector <vector <int> > &g, int u, int &timer, vector <int> &timeIn, vector <int> &timeOut) {
	timeIn[u] = timer++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(g, v, timer, timeIn, timeOut);
	}
	timeOut[u] = timer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> p(n);
	vector <vector <int> > g(n);
	int root = -1;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		if (p[i] == -1) {
			assert(root == -1);
			root = i;
		} else {
			g[p[i]].push_back(i);
		}
	}
	assert(root != -1);
	int timer = 1;
	vector <int> timeIn(n), timeOut(n);
	dfs(g, root, timer, timeIn, timeOut);
	segmentTree st(n);
	vector <int> node(m), color(m);
	for (int i = 0; i < m; i++) {
		cin >> node[i] >> color[i];
		node[i]--;
	}
	set <int> S;
	for (int i = m - 1; i >= 0; i--) {
		if (st.query(timeIn[node[i]], timeOut[node[i]] - 1) == false) {
			S.insert(color[i]);
		}
		st.update(timeIn[node[i]], timeOut[node[i]] - 1);
	}
	cout << S.size() << "\n";
}
