#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;

const int N = 200005;

int n, m;
int a[N], b[N];

long long solve() {
	if (n == 1) {
		return 0;
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if ((i == 0) || (a[i] != 0) || (a[i] == 0 && (a[i - 1] != 0))) {
			v.push_back(a[i]);
		}
	}
	n = v.size();
	if (n == 1) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = v[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (i == 0) {
				int p = lower_bound(b, b + m, a[i + 1]) - b;
				int v1 = inf;
				if (p < m) {
					v1 = abs(b[p] - a[i + 1]);
					a[i] = b[p];
				}
				if (p > 0) {
					int v2 = abs(b[p - 1] - a[i + 1]);
					if (v2 < v1) {
						v1 = v2;
						a[i] = b[p - 1];
					}
				}
			} else if (i == n - 1) {
				int p = lower_bound(b, b + m, a[i - 1]) - b;
				int v1 = inf;
				if (p < m) {
					v1 = abs(b[p] - a[i - 1]);
					a[i] = b[p];
				}
				if (p > 0) {
					int v2 = abs(b[p - 1] - a[i - 1]);
					if (v2 < v1) {
						v1 = v2;
						a[i] = b[p - 1];
					}
				}
			} else {
				int x = min(a[i - 1], a[i + 1]);
				int y = max(a[i - 1], a[i + 1]);
				int p = lower_bound(b, b + m, x) - b;
				int v1 = inf;
				if (p < m) {
					v1 = abs(a[i - 1] - b[p]) + abs(a[i + 1] - b[p]);
					a[i] = b[p];
				}
				if (p > 0) {
					int v2 = abs(a[i - 1] - b[p - 1]) + abs(a[i + 1] - b[p - 1]);
					if (v2 < v1) {
						v1 = v2;
						a[i] = b[p - 1];
					}
				}
			}
		}
		if (i > 0) {
			ans += abs(a[i] - a[i - 1]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(b, b + m);
		cout << solve() << "\n";
	}
}
