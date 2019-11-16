// Problem: pace=1&num=1613
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 70005;

int n, a[N], q, x, y, z;
map<int, vector<int> > m;
map<int, vector<int> >::iterator it;
vector<int>::iterator xx;

int main() {
	//freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]].push_back(i + 1);
	}
	cin >> q;
	while (q--) {
		cin >> x >> y >> z;
		it = m.find(z);
		if (it == m.end()) {
			cout << "0";
		} else {
			xx = lower_bound(it->second.begin(), it->second.end(), x);
			if (xx != it->second.end() && *xx <= y) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
	}
	cout << "\n";
}
