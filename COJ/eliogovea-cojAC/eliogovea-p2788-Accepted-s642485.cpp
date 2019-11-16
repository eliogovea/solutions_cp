#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1000000;

int n, k, x, g, a[MAXN + 5], sol = -1;

inline int get(int x) {
	int lo = x - k;
	if (lo < 0) lo = 0;
	int hi = x + k;
	if (hi > MAXN) hi = MAXN;
	int r = a[hi];
	if (lo) r -= a[lo - 1];
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n >> k;
	while (n--) {
		cin >> g >> x;
		a[x] += g;
	}
	for (int i = 1; i <= MAXN; i++) a[i] += a[i - 1];
	for (int i = 0, tmp; i <= MAXN; i++) {
		tmp = get(i);
		if (sol < tmp) sol = tmp;
	}
	cout << sol << '\n';
}
