#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, l, r;
int bit[N];

void update(int p, int v) {
	while (p < N) {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long ans = 0;
	while (n--) {
		cin >> l >> r;
		int valL = query(l);
		if (valL != 0) {
			update(l, -valL);
			update(l + 1, valL);
		}
		int valR = query(r);
		if (valR != 0) {
			update(r, -valR);
			update(r + 1, valR);
		}
		cout << valL + valR << "\n";
		if (l + 1 < r) {
			update(l + 1, 1);
			update(r, -1);
		}
	}
}
