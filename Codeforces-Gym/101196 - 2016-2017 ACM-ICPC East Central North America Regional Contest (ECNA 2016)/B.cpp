// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196B

#include <bits/stdc++.h>

using namespace std;

int n;
int score[15][15];
string names[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> names[i];
	}
	int wo = 0, wwo = 0;
	int bo = 1, bbo = 1;
	int wd = 2, wwd = 2;
	int bd = 3, bbd = 3;
	queue <int> Q;
	for (int i = 4; i < n; i++) {
		Q.push(i);
	}
	string s;
	cin >> s;
	int best = 0;
	vector <pair <int, int> > ans;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'W') {
			score[wwo][wwd]++;
			swap(wo, wd);
			int x = score[bbo][bbd];
			if (x > best) {
				ans.clear();
				best = x;
				ans.push_back(make_pair(bbo, bbd));
			} else if (x == best) {
			    ans.push_back(make_pair(bbo, bbd));
			}
			score[bbo][bbd] = 0;
			Q.push(bd);
			bd = bo;
			bbo = bd;
			bo = Q.front();
			bbd = bo;
			Q.pop();
		} else {
			score[bbo][bbd]++;
			swap(bo, bd);
			int x = score[wwo][wwd];
			if (x > best) {
				best = x;
				ans.clear();
				ans.push_back(make_pair(wwo, wwd));
			} else if (x == best) {
				ans.push_back(make_pair(wwo, wwd));
			}
			score[wwo][wwd] = 0;
			Q.push(wd);
			wd = wo;
			wwo = wd;
			wo = Q.front();
			wwd = wo;
			Q.pop();
		}
	}
	if (s[s.size() - 1] == 'W') {
		int x = score[wwo][wwd];
		if (x > best) {
			best = x;
			ans.clear();
			ans.push_back(make_pair(wwo, wwd));
		} else if (x == best) {
		    ans.push_back(make_pair(wwo, wwd));
		}
	} else {
		int x = score[bbo][bbd];
		if (x > best) {
			best = x;
			ans.clear();
			ans.push_back(make_pair(bbo, bbd));
		} else if (x == best) {
		    ans.push_back(make_pair(bbo, bbd));
		}
	}
	//cerr << best << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << names[ans[i].first] << " " << names[ans[i].second] << "\n";
	}
}
