// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147I

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-11;

const int N = 100005;

int t;
int n;
int R;
double x[N], y[N], r[N];

struct event {
	double x;
	int r;
	bool end;
	event() {}
	event(double _x, int _r, bool _end) : x(_x), r(_r), end(_end) {}
};

bool operator < (const event &a, const event &b) {
	if (fabs(a.x - b.x) > EPS) {
		return a.x < b.x;
	}
	return a.end < b.end;
}

event E[2 * N];
int sz = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("walk.in", "r", stdin);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> R;
		sz = 0;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			if (r > R || y + r > R || y - r < -R) {
				continue;
			}
			double xin = (double)x - sqrt(((double)(R - r) * (R - r)) - ((double)y * y));
			double xout =(double)x + sqrt(((double)(R - r) * (R - r)) - ((double)y * y));
			E[sz++] = event(xin, r, false);
			E[sz++] = event(xout, r, true);
		}
		sort(E, E + sz);
		long long curSum = 0;
		long long best = 0;
		for (int i = 0;i < sz; i++) {
			if (!E[i].end) {
				curSum += E[i].r;
			} else {
				curSum -= E[i].r;
			}
			best = max(best, curSum);
		}
		cout << best << "\n";
	}
}
