// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246B

#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[150];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			s[i][j] -= '0';
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != 0) {
				ans += 2;
			}
		}
	}

	//cerr << ans << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				ans += (int)s[i][j];
			} else {
				ans += abs(((int)s[i][j]) - ((int)s[i - 1][j]));
			}
			if (i == n - 1) {
                ans += (int)s[i][j];
			}
		}
	}

	//cerr << ans << "\n";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				ans += (int)s[j][i];
			} else {
				ans += abs(((int)s[j][i]) - ((int)s[j][i - 1]));
			}
			if (i == m - 1) {
                ans += (int)s[j][i];
			}
		}
	}

	cout << ans << "\n";

}
