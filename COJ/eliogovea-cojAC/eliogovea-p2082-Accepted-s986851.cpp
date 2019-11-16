#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		vector <int> v(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'X') {
					v[i] |= (1 << j);
				}
			}
		}
		int ans = -1;
		for (int mask = 0; mask < (1 << m); mask++) {
			vector <int> nv = v;
			int cnt = 0;
			for (int i = 0; i < m; i++) {
				if (mask & (1 << i)) {
					cnt++;
					if (i > 0) {
						nv[0] ^= (1 << (i - 1));
					}
					nv[0] ^= (1 << i);
					if (i + 1 < m) {
						nv[0] ^= (1 << (i + 1));
					}
					if (n > 1) {
						nv[1] ^= (1 << i);
					}
				}
			}
			for (int r = 1; r < n; r++) {
				for (int i = 0; i < m; i++) {
					if (nv[r - 1] & (1 << i)) {
						cnt++;
						nv[r - 1] ^= (1 << i);
						if (i > 0) {
							nv[r] ^= (1 << (i - 1));
						}
						nv[r] ^= (1 << i);
						if (i + 1 < m) {
							nv[r] ^= (1 << (i + 1));
						}
						if (r + 1 < n) {
							nv[r + 1] ^= (1 << i);
						}
					}
				}
			}
			if (nv[n - 1] == 0) {
				if (ans == -1 || cnt < ans) {
					ans = cnt;
				}
			}
		}
		if (ans == -1) {
			cout << "Damaged billboard.\n";
		} else {
			cout << "You have to tap " << ans << " tiles.\n";
		}
	}
}
