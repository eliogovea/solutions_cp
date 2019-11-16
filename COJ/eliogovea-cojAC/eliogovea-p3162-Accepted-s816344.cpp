#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, q;
string str;

int sqrtn;

char ch;
int a, b;

int v[N];

int sum[1005];
int mn[1005];
int mx[1005];

int upd[1005];

void update(int p, int l, int r) {
	if (upd[p]) {
		sum[p] = -sum[p];
		int xx = mn[p];
		int yy = mx[p];
		mn[p] = -yy;
		mx[p] = -xx;
		for (int i = 0; i < sqrtn && sqrtn * p + i < n; i++) {
			v[sqrtn * p + i] = -v[sqrtn * p + i];
		}
		upd[p] ^= 1;
	}
	while (l <= r) {
		v[l] = -v[l];
		l++;
	}
	sum[p] = 0;
	for (int i = 0; i < sqrtn && sqrtn * p + i < n; i++) {
		sum[p] += v[sqrtn * p + i];
		if (i == 0 || sum[p] > mx[p]) {
			mx[p] = sum[p];
		}
		if (i == 0 || sum[p] < mn[p]) {
			mn[p] = sum[p];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> str;
    sqrtn = sqrt(n);
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			v[i] = 1;
		} else {
			v[i] = -1;
		}
		int p = i / sqrtn;
		sum[p] += v[i];
		if ((i % sqrtn == 0) || sum[p] > mx[p]) {
			mx[p] = sum[p];
		}
		if ((i % sqrtn == 0) || sum[p] < mn[p]) {
			mn[p] = sum[p];
		}
	}
	cin >> q;
	while (q--) {
		cin >> ch >> a >> b;
		a--;
		b--;
		if (ch == 'q') {
            if ((b - a) % 2 == 0) {
                cout << "0\n";
                continue;
            }
			int pa = a / sqrtn;
			int pb = b / sqrtn;
			if (pa == pb) {
				int s = 0;
				bool ok = true;
				for (int i = a; i <= b; i++) {
					s += v[i] * (upd[pa] ? -1 : 1);
					if (s < 0) {
						ok = false;
					}
				}
				cout << (ok && (s == 0)) << "\n";
			} else {
				int s = 0;
				bool ok = true;
				while (a % sqrtn) {
					s += v[a] * (upd[pa] ? -1 : 1);
					if (s < 0) {
						ok = false;
						break;
					}
					a++;
				}
				if (!ok) {
					cout << "0\n";
					continue;
				}
				pa = a / sqrtn;
				while (pa != pb) {
					int xx = mn[pa];
					if (upd[pa]) {
						xx = -mx[pa];
					}
					if (s + xx < 0) {
						ok = false;
						break;
					}
					s += sum[pa] * (upd[pa] ? -1 : 1);
					if (s < 0) {
						ok = false;
						break;
					}
					a += sqrtn;
					pa++;
				}
				if (!ok) {
					cout << "0\n";
					continue;
				}
				while (a <= b) {
					s += v[a] * (upd[pa] ? -1 : 1);
					if (s < 0) {
						ok = false;
						break;
					}
					a++;
				}
				if (!ok) {
					cout << "0\n";
					continue;
				}
				cout << (s == 0) << "\n";
			}
		} else {
			int pa = a / sqrtn;
			int pb = b / sqrtn;
			if (pa == pb) {
				update(pa, a, b);
			} else {
				update(pa, a, sqrtn * (pa + 1) - 1);
				pa++;
				a = sqrtn * pa;
				while (pa != pb) {
					upd[pa] ^= 1;
					pa++;
				}
				a = sqrtn * pa;
				update(pa, a, b);
			}
		}
	}
}
