// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116A

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> c(n);
		vector <vector <int> > v(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			v[i].resize(c[i]);
			for (int j = 0; j < c[i]; j++) {
				cin >> v[i][j];
			}
			sort(v[i].begin(), v[i].end());
		}
		set <pair <int, vector <int> > > S;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += v[i][0];
			}
			S.insert(make_pair(sum, vector <int> (n, 0)));
		}
		vector <int> ans;
		while (true) {
			pair <int, vector <int> > p = *S.begin();
			S.erase(S.begin());
			ans.push_back(p.first);
			if (ans.size() == k) {
                break;
			}
			for (int i = 0; i < n; i++) {
				if (p.second[i] + 1 < c[i]) {
					p.first = p.first - v[i][p.second[i]] + v[i][p.second[i] + 1];
					p.second[i]++;
					S.insert(p);
					while (S.size() > k - ans.size()) {
						S.erase(--S.end());
					}
					p.first = p.first - v[i][p.second[i]] + v[i][p.second[i] - 1];
					p.second[i]--;
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i + 1 < ans.size()) {
				cout << " ";
			}
		}
		cout << "\n";
	}

}
