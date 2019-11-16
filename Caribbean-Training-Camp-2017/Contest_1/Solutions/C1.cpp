#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

const int N = 150 * 1000 + 10;

int n, m;
double c;
int x[N];
double d[N];
double p[N];

double a[N];
double sa[N];

struct data {
	bool isNull;
	double all;
	double bestLeft;
	double bestRight;
	double best;
	data() {
		isNull = true;
	}
};

data merge(const data &a, const data &b) {
	if (a.isNull) {
		return b;
	}
	if (b.isNull) {
		return a;
	}
	data res;
	res.isNull = false;
	res.all = a.all + b.all;
	res.bestLeft = max(a.bestLeft, a.all + b.bestLeft);
	res.bestRight = max(b.bestRight, b.all + a.bestRight);
	res.best = max(0.0, max(max(a.best, b.best), max(res.all, a.bestRight + b.bestLeft)));
	return res;
}

data st[4 * N];

void build(int x, int l, int r) {
	if (l == r) {
		st[x].isNull = false;
		st[x].all = a[l];
		st[x].bestLeft = st[x].bestRight = st[x].best = max(0.0, a[l]);
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		st[x] = merge(st[2 * x], st[2 * x + 1]);
	}
}

data query(int x, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return data();
	}
	if (ql <= l && r <= qr) {
		return st[x];
	}
	int mid = (l + r) >> 1;
	return merge(query(2 * x, l, mid, ql, qr), query(2 * x + 1, mid + 1, r, ql, qr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(13);

	//freopen("input001.txt", "r", stdin);

	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (i != 0) {
			d[i] = x[i] - x[i - 1];
		}
	}
	for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i] /= 100.0;
	}

	n--;
	for (int i = 1; i <= n; i++) {
		a[i] = d[i] / 2.0 - c * p[i];
	}

	for (int i = 1; i <= n; i++) {
        sa[i] = sa[i - 1] + a[i];
	}

	// for (int i = 1; i <= n; i++) {
        // cerr << d[i] << "\t";
	// }
	// cerr << "\n\n";
	// for (int i = 1; i <= n; i++) {
        // cerr << p[i] << "\t";
	// }
	// cerr << "\n\n";
	// for (int i = 1; i <= n; i++) {
        // cerr << a[i] << "\t";
	// }
	// cerr << "\n\n";

	build(1, 1, n);
	int s, e;
	double ans = 0.0;
	// double slow = 0.0;
	while (m--) {
		cin >> s >> e;
		s--;
		e--;

		// double slowAns = 0.0;
		// int l = -1, r = -1;
		// for (int i = s + 1; i <= e; i++) {
            // for (int j = i; j <= e; j++) {
                // if (sa[j] - sa[i - 1] > slowAns) {
                    // l = i;
                    // r = j;
                    // slowAns = sa[j] - sa[i - 1];
                // }
            // }
		// }
		// slow += slowAns;

		// cerr << s + 1 << " " << e << " " << l << " " << r << " " << slowAns << "\n";

		double val = query(1, 1, n, s + 1, e).best;
		ans += val;
		// assert(abs(val - slowAns) < EPS);
		//cerr << val << " " << slowAns << "\n";
	}
	// slow *= 0.5;
	// cerr << slow << "\n";
    // ans = 0.5 * ans;
	cout << fixed << ans << "\n";
}
