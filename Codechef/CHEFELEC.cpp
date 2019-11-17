#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int t;
int n;
string s;
long long x[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		vector <int> v;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				v.push_back(i);
			}
		}
		long long ans = 0;
		ans += x[v[0]] - x[0];
		ans += x[n - 1] - x[v.back()];
		for (int i = 0; i + 1 < (int)v.size(); i++) {
			if (v[i] + 1 == v[i + 1]) {
				continue;
			}
			long long best = 0;
			for (int j = v[i]; j < v[i + 1]; j++) {
				best = max(best, x[j + 1] - x[j]);
			}
			ans += x[v[i + 1]] - x[v[i]] - best;
		}
		cout << ans << "\n";
	}
}

