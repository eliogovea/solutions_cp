#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int t, n, a[10005];

vector<int> g[105], pos[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (__gcd(i, j) == 1) {
				g[i].push_back(j);
			}
		}
	}
	cin >> t;
	while (t--) {
		for (int i = 1; i <= N; i++) {
			pos[i].clear();
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pos[a[i]].push_back(i);
		}
		for (int i = 0; i < n; i++) {
			int x = -1;
			for (int j = 0; j < g[a[i]].size(); j++) {
				int v = g[a[i]][j];
				int p = lower_bound(pos[v].begin(), pos[v].end(), i + 1) - pos[v].begin();
				if (p < pos[v].size()) {
					if (x == -1 || pos[v][p] < x) {
						x = pos[v][p];
					}
				}
			}
			if (x == -1) {
                cout << x;
			} else {
                cout << x + 1;
			}
			if (i + 1 < n) {
                cout << " ";
			}
		}
		cout << "\n";
	}
}
