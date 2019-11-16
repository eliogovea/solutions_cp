#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, c, m, x, q, n;
	while (cin >> a >> c >> m >> x >> q >> n) {
		vector <int> f(m);
		if (n <= m) {
			f[x]++;
			for (int i = 1; i < n; i++) {
				x = (a * x + c) % m;
				f[x]++;
			}
		} else {
			vector <int> depth(m, -1);
			int curDepth = 0;
			while (depth[x] == -1) {
				f[x]++;
				n--;
				depth[x] = curDepth++;
				x = (a * x + c) % m;
			}
			int cycleStart = x;
			int cycleLength = curDepth - depth[cycleStart];
			int cnt = n / cycleLength;
			int cx = x;
			for (int i = 0; i < cycleLength; i++) {
				f[cx] += cnt;
				cx = (a * cx + c) % m;
			}
			assert(cx == x);
			n %= cycleLength;
			for (int i = 0; i < n; i++) {
				f[cx]++;
				cx = (a * cx + c) % m;
			}
		}
		for (int i = 1; i < m; i++) {
			f[i] += f[i - 1];
		}
		while (q--) {
			int p;
			cin >> p;
			cout << (int)(lower_bound(f.begin(), f.end(), p) - f.begin()) << "\n";
		}
	}
}
