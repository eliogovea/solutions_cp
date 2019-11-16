// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513D

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int n;
	long long m;
	cin >> n >> m;
	vector <pair <long long, int> > a, b;
	for (int i = 0; i < n; i++) {
		long long x;
		int l;
		cin >> x >> l;
		if (l == 1) {
			a.push_back(make_pair(x, i));
		} else {
			b.push_back(make_pair(x, i));
		}
	}
	sort(a.begin(), a.end(), greater <pair <long long, int> > ());
	sort(b.begin(), b.end(), greater <pair <long long, int> > ());
	vector <long long> sa(a.size() + 1);
	sa[0] = 0;
	for (int i = 1; i <= a.size(); i++) {
		sa[i] = sa[i - 1] + a[i - 1].first;
	}
    vector <long long> sb(b.size() + 1);
	sb[0] = 0;
	for (int i = 1; i <= b.size(); i++) {
		sb[i] = sb[i - 1] + b[i - 1].first;
	}
	int ansCnt = n;
	int ansCl = a.size();
	int ansCh = b.size();
	for (int cl = 0; cl <= a.size(); cl++) {
		long long curSum = sa[cl];
		long long needSum = m - curSum;
		if (needSum < 0) {
			needSum = 0;
		}
		if (needSum > sb.back()) {
			continue;
		}
		int pos = lower_bound(sb.begin(), sb.end(), needSum) - sb.begin();
		int cnt = cl + pos;
		//cerr << "-->> " << cnt << " " << curSum << " " << needSum << " " << pos << "\n";
		if (cnt <= ansCnt) {
			ansCnt = cnt;
			ansCl = cl;
			ansCh = cnt - cl;
		}
	}
	cout << ansCnt << " " << ansCl << "\n";
	vector <int> id;
	for (int i = 0; i < ansCl; i++) {
		id.push_back(a[i].second);
	}
	for (int i = 0; i < ansCh; i++) {
		id.push_back(b[i].second);
	}
	for (int i = 0; i < id.size(); i++) {
		cout << id[i] + 1;
		if (i + 1 < id.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}
