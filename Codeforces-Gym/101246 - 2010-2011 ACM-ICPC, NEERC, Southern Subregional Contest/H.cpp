// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246H

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;

struct pt {
	int x, y, id;
} P[N];

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y > b.y;
}

int stMax[4 * N];

void buildMax(int id, int l, int r) {
	stMax[id] = 0;
	if (l != r) {
		int mid = (l + r) >> 1;
		buildMax(2 * id, l, mid);
		buildMax(2 * id + 1, mid + 1, r);
	}
}

void updateMax(int id, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		stMax[id] = max(stMax[id], v);
	} else {
		int mid = (l + r) >> 1;
		updateMax(2 * id, l, mid, p, v);
		updateMax(2 * id + 1, mid + 1, r, p, v);
		stMax[id] = max(stMax[2 * id], stMax[2 * id + 1]);
	}
}

int queryMax(int id, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return stMax[id];
	}
	int mid = (l + r) >> 1;
	return max(queryMax(2 * id, l, mid, ql, qr), queryMax(2 * id + 1, mid + 1, r, ql, qr));
}

int stMin[4 * N];

void buildMin(int id, int l, int r) {
	stMin[id] = 1e9;
	if (l != r) {
		int mid = (l + r) >> 1;
		buildMin(2 * id, l, mid);
		buildMin(2 * id + 1, mid + 1, r);
	}
}

void updateMin(int id, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		stMin[id] = min(stMax[id], v);
	} else {
		int mid = (l + r) >> 1;
		updateMin(2 * id, l, mid, p, v);
		updateMin(2 * id + 1, mid + 1, r, p, v);
		stMin[id] = min(stMin[2 * id], stMin[2 * id + 1]);
	}
}

int queryMin(int id, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return 1e9;
	}
	if (l >= ql && r <= qr) {
		return stMin[id];
	}
	int mid = (l + r) >> 1;
	return min(queryMin(2 * id, l, mid, ql, qr), queryMin(2 * id + 1, mid + 1, r, ql, qr));
}


vector <int> Y;

int dp[N];

bool ok[N];
vector <pair <int, int> > v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	Y.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i].x >> P[i].y;
		P[i].id = i;
		Y[i] = P[i].y;
	}

	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (int i = 0; i < n; i++) {
		P[i].y = lower_bound(Y.begin(), Y.end(), P[i].y) - Y.begin();
	}

	sort(P, P + n);

	buildMax(1, 0, Y.size() - 1);
	for (int i = n - 1; i >= 0; i--) {
        if (P[i].y + 1 == Y.size()) {
            dp[P[i].id] = 1;
        } else {
            dp[P[i].id] = 1 + queryMax(1, 0, Y.size() - 1, P[i].y + 1, Y.size() - 1);
        }
		//cerr << P[i].id + 1 << " " << dp[ P[i].id ] << "\n";
		updateMax(1, 0, Y.size() - 1, P[i].y, dp[P[i].id]);
	}

	buildMin(1, 0, Y.size() - 1);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, dp[i]);
	}

	//cerr << "mx " << mx << "\n";
	for (int i = 0; i < n; i++) {
		if (dp[P[i].id] == mx) {
			ok[P[i].id] = true;
		} else {
			if (P[i].y > 0) {
				int mn = queryMin(1, 0, Y.size() - 1, 0, P[i].y - 1);
				if (mn <= dp[P[i].id] + 1) {
					ok[P[i].id] = true;
				}
			}
		}
		if (ok[P[i].id]) {
			updateMin(1, 0, Y.size() - 1, P[i].y, dp[P[i].id]);
			v.push_back(make_pair(dp[P[i].id], P[i].id));
		}
	}
	sort(v.begin(), v.end());
	vector <int> a, b;
	for (int i = 0, j = 0; i <= v.size(); i++) {
		if (i < v.size()) {
            //cerr << "--->> " << v[i].first << " " << v[i].second + 1 << "\n";
			a.push_back(v[i].second + 1);
		}
		if (i == v.size() || v[i].first != v[j].first) {
			if (i - j == 1) {
                    //cerr << "insert b " << v[j].second << "\n";
				b.push_back(v[j].second + 1);
			}
			j = i;
		}
	}
	sort(a.begin(), a.end());
	cout << a.size();
	for (int i = 0; i < a.size(); i++) {
		cout << " " << a[i];
	}
	cout << "\n";
	sort(b.begin(), b.end());
	cout << b.size();
	for (int i = 0; i < b.size(); i++) {
		cout << " " << b[i];
	}
	cout << "\n";
}
