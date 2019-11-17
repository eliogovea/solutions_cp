#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <pair <int, int> > all;
		// all.reserve(n * k);
		int answer = 0;
		for (int i = 0; i < n; i++) {
			int len;
			cin >> len;
			vector <int> v(len);
			vector <bool> mark(k);
			for (int j = 0; j < len; j++) {
				cin >> v[j];
				v[j]--;
				mark[v[j]] = true;
			}
			if (i != 0) {
				vector <int> cnt(i);
				for (int j = 0; j < all.size(); j++) {
					if (!mark[all[j].first]) {
						cnt[all[j].second]++;
					}
				}
				for (int j = 0; j < i; j++) {
					if (cnt[j] == k - len) {
						answer++;
					}
				}
			}
			for (int j = 0; j < len; j++) {
				all.push_back(make_pair(v[j], i));
			}
		}
		cout << answer << "\n";
	}
}

/*
3
2 2
1 1
1 1
3 2
2 1 2
2 1 2
2 1 2
3 4
3 1 2 3
4 1 2 3 4
3 2 3 4

0
3
3
*/

