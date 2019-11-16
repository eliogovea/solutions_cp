#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, m, b;
int x[N];
vector <pair <int, int> > v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		int y, p, q;
		cin >> y >> p >> q;
		v[y].push_back(make_pair(q, p));
	}
	for (int i = 0; i < n; i++) {
		sort(v[x[i]].begin(), v[x[i]].end());
		for (int j = ((int)(v[x[i]].size())) - 2; j >= 0; j--) {
			v[x[i]][j].second = min(v[x[i]][j].second, v[x[i]][j + 1].second);
		}
	}
	int lo = 1;
	int hi = 1000000;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int val = 0;
		for (int i = 0; i < n; i++) {
			int pos = lower_bound(v[x[i]].begin(), v[x[i]].end(), make_pair(mid, -1)) - v[x[i]].begin();
			if (pos == v[x[i]].size()) {
				val = b + 1;
				break;
			}
			val += v[x[i]][pos].second;
			if (val > b) {
				val = b + 1;
				break;
			}
		}
		if (val <= b) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	if (ans == -1) {
		cout << "No task.\n";
	} else {
		cout << ans << "\n";
	}
}
