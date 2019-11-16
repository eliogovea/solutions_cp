#include <bits/stdc++.h>

using namespace std;

int tc, n;
long long a[1000005];
map<long long, int> m;
map<long long, int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		m.clear();
		long long s = 0;
		long long ans = 0;
		m[0] = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
			it = m.find(s - 47LL);
			if (it != m.end()) {
				ans += it->second;
			}
			m[s]++;
		}
		cout << ans << "\n";
	}
}

