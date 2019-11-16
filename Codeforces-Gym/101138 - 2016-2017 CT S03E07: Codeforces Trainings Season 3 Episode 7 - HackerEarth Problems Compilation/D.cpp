// 2016-2017 CT S03E07: Codeforces Trainings Season 3 Episode 7 - HackerEarth Problems Compilation
// 101138D

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct query {
	int ind;
	int sign;
	int L, R;
	query() {}
	query(int _ind, int _sign, int _L, int _R) {
		ind = _ind;
		sign = _sign;
		L = _L;
		R = _R;
		if (L > R) {
			swap(L, R);
		}
	}
};

int bs;

bool cmp(const query &a, const query &b) {
	return make_pair(a.L / bs, a.R) < make_pair(b.L / bs, b.R);
}

const int N = 50005;
int n, q;
int a[N];
query qs[4 * N];
int fL[N];
int fR[N];
long long ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		qs[4 * i + 0] = query(i, 1, r1, r2);
		qs[4 * i + 1] = query(i, -1, l1 - 1, r2);
		qs[4 * i + 2] = query(i, -1, l2 - 1, r1);
		qs[4 * i + 3] = query(i, 1, l1 - 1, l2 - 1);
	}

	bs = sqrt(n);

	sort(qs, qs + (4 * n), cmp);

	int L = 0;

	int R = 0;

    LL A = 0;

	for (int i = 0; i < 4 * q; i++) {

		while (L < qs[i].L) { // add
			A += fR[a[L + 1]];
			fL[a[L + 1]]++;
			L++;
		}
		while (L > qs[i].L) { // remove
			A -= fR[a[L]];
			fL[a[L]]--;
			L--;
		}
		while (R < qs[i].R) { // add
			A += fL[a[R + 1]];
			fR[a[R + 1]]++;
			R++;
		}
		while (R > qs[i].R) {
			A -= fL[a[R]];
			fR[a[R]]--;
			R--;
		}
		if (qs[i].sign > 0) {
			ans[qs[i].ind] += A;
		} else {
			ans[qs[i].ind] -= A;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}
