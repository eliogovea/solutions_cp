#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int t;
int n;
int a[N], b[N];
vector <int> v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		int cnt = unique(b, b + n) - b;
		for (int i = 0; i < cnt; i++) {
            v[i].clear();
		}
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(b, b + cnt, a[i]) - b;
			v[a[i]].push_back(i);
		}
		long long ans = 0;
		for (int d = n - 1; d > 0; d--) {
			set <int> S;
			S.insert(-1);
			S.insert(d + 1);
			int total = (d + 1) * (d + 2) / 2;
			for (int c = d; c > 0; c--) {
				if (S.find(c) == S.end()) {
					int x = a[c];
					for (int i = 0; i < v[x].size(); i++) {
                        if (v[x][i] > d) {
                            continue;
                        }
						set <int>::iterator it1 = S.lower_bound(v[x][i]);
						set <int>::iterator it2 = it1; it1--;
						int dt = *it2 - *it1 - 1;
						int d1 = v[x][i] - *it1 - 1;
						int d2 = *it2 - v[x][i] - 1;
						total = total - dt * (dt + 1) / 2 + d1 * (d1 + 1) / 2 + d2 * (d2 + 1) / 2;
						S.insert(v[x][i]);
					}
				}
				//cout << "DEBUG " << d << " " << total << "\n";
				ans += (long long)total;
			}
		}
		cout << ans << "\n";
	}
}

