// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116I

#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    if (a.second == 7) {
        return true;
    }
    if (b.second == 7) {
        return false;
    }
    return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> f(55);
		while (n--) {
			for (int i = 0; i < 6; i++) {
				int x;
				cin >> x;
				f[x]++;
			}
		}
		vector <pair <int, int> > v;
		for (int i = 1; i <= 49; i++) {
			v.push_back(make_pair(f[i], i));
		}
		sort(v.begin(), v.end(), cmp);
		vector <int> ans;
		for (int i = 0; i < 6; i++) {
			ans.push_back(v[i].second);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i + 1 < ans.size()) {
                cout << " ";
            }
		}
		cout << "\n";
	}
}
