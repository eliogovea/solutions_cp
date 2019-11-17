#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 300005;
const int M = 100;
int n, q;
LL a[N];

LL sum[M + 2][N];

inline LL get(int start, int diff) {
	if (sum[diff][start]) {
		return sum[diff][start];
	}
	sum[diff][start] = a[start];
	if (start + diff <= n) {
		sum[diff][start] += get(start + diff, diff);
	}
	return sum[diff][start];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> q;
	int x, y;
	while (q--) {
		cin >> x >> y;
		if (y < M) {
			cout << get(x, y) << "\n";
		} else {
			LL s = 0;
			for (int i = x; i <= n; i += y) {
				s += a[i];
			}
			cout << s << "\n";
		}
	}
}

