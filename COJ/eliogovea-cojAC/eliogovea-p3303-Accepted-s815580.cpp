#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
vector<int> v[1000005];

bool mark[101];
int ans[101][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > mx) {
			mx = a[i];
		}
		v[a[i]].push_back(i);
	}
	int q;
	cin >> q;
	int x, y, c;
	while (q--) {
		cin >> x >> y >> c;
		if (c > 100) {
			int res = 0;
			for (int i = c; i <= mx; i += c) {
				res += upper_bound(v[i].begin(), v[i].end(), y) - lower_bound(v[i].begin(), v[i].end(), x);
			}
			cout << res << "\n";
			continue;
		}
		if (mark[c]) {
			cout << ans[c][y] - ans[c][x - 1] << "\n";
			continue;
		} else {
			for (int i = 1; i <= n; i++) {
				ans[c][i] = ans[c][i - 1];
				if (a[i] % c == 0) {
                    ans[c][i]++;
				}
			}
			mark[c] = true;
			cout << ans[c][y] - ans[c][x - 1] << "\n";
		}
	}
}
