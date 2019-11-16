#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100005;

pair<int, char> a[N];
map<int, int> m;
map<int, int>::iterator it;
int n, ans ;

int solve() {
	m.clear();
	int ret = 0;
	int d = 0;
	m[0] = a[0].first;
	for (int i = 0; i < n; i++) {
		if (a[i].second == 'W') d++;
		else d--;
		if (d >= 0) {
			int rem = d & 1;
			it = m.find(rem);
			if (it != m.end()) {
				int tmp = abs(a[i].first - it->second);
				if (tmp > ret) ret = tmp;
			} else {
				m[rem] = a[i + 1].first;
			}
		} else {
			it = m.find(d);
			if (it != m.end()) {
				int tmp = abs(a[i].first - it->second);
				if (tmp > ret) ret = tmp;
			}
		}
		it = m.find(d);
		if (it == m.end()) m[d] = a[i + 1].first;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	ans = solve();
	sort(a, a + n, greater<pair<int, char> >());
	int tmp = solve();
	if (tmp > ans) ans = tmp;
	cout << ans << "\n";
}
