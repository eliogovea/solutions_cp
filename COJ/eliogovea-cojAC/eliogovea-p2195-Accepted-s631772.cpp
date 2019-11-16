#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], b[MAXN];
set<pair<int, int> > s;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (!s.empty() && s.begin()->first < a[i]) {
			b[s.begin()->second] = i;
			s.erase(s.begin());
		}
		s.insert(make_pair(a[i], i));
	}
	for (int i = 1; i <= n; i++)
		cout << b[i] << '\n';
}
