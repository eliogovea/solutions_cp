// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503F

#include <bits/stdc++.h>

using namespace std;

struct data {
	int mx;
	int pos;
};

data merge(const data &a, const data &b) {
	if (a.mx > b.mx) {
		return a;
	}
	return b;
}

bool operator < (const data &a, const data &b) {
	if (a.mx != b.mx) {
		return a.mx > b.mx;
	}
	return a.pos > b.pos;
}

const int N = 1000000;

int n;
int a[N + 5];
data t[4 * (N + 1) + 10];

void build(int x, int l, int r) {
	t[x].mx = 0;
	t[x].pos = -1;
	if (l != r) {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
	}
}

void update(int x, int l, int r, int p, int v, int ind) {
	if (p > r || p < l) {
		return;
	}
	if (l == r) {
		if (v > t[x].mx) {
			t[x].mx = v; t[x].pos = ind;
		}
	} else {
		int mid = (l + r) >> 1;
		update(2 * x, l, mid, p, v, ind);
		update(2 * x + 1, mid + 1, r, p, v, ind);
		t[x] = merge(t[2 * x], t[2 * x + 1]);
	}
}

data query(int x, int l, int r, int ql, int qr) {
	if (l > r || l > qr || r < ql) {
		return (data) {-1, -1};
	}
	if (l >= ql && r <= qr) {
		return t[x];
	}
	int mid = (l + r) >> 1;
	data q1 = query(2 * x, l, mid, ql, qr);
	data q2 = query(2 * x + 1, mid + 1, r, ql, qr);
	return merge(q1, q2);
}

int dp[N];
int from[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 0, N);
	for (int i = 0; i < n; i++) {
		data q1 = query(1, 0, N, 0, a[i] - 2);
		data q2 = query(1, 0, N, a[i], a[i]);
		data q3 = query(1, 0, N, a[i] + 2, N);
		data q[] = {q1, q2, q3};
		sort(q, q + 3);
		dp[i] = q[0].mx + 1;
		from[i] = q[0].pos;
		update(1, 0, N, a[i], dp[i], i);
		//cerr << i << " " << a[i] << " " << dp[i] << " " << from[i] << "\n";
	}
	int id = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] > dp[id]) {
			id = i;
		}
	}
	//cerr << id << "\n";
	vector <int> ans;
	int cur = id;
	while (id != -1) {
		ans.push_back(id);
		id = from[id];
	}
	cout << n - ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << a[ans[i]];
		if (i > 0) {
			cout << " ";
		}
	}
	cout << "\n";
}
