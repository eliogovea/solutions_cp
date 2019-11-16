#include <bits/stdc++.h>

using namespace std;

struct entry {
	int index;
	int first;
	int second;
};

bool operator < (const entry &a, const entry &b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.index < b.index;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector <entry> sa(n);
	for (int i = 0; i < n; i++) {
		sa[i].index = i;
		sa[i].first = s[i];
		sa[i].second = -1;
	}
	sort(sa.begin(), sa.end());
	vector <int> c(n);
	c[sa[0].index] = 0;
	for (int i = 1; i < n; i++) {
		c[sa[i].index] = c[sa[i - 1].index];
		if (sa[i].first != sa[i - 1].first) {
			c[sa[i].index]++;
		}
	}
	for (int len = 2; len <= 2 * n; len *= 2) {
		for (int i = 0; i < n; i++) {
			sa[i].index = i;
			sa[i].first = c[i];
			sa[i].second = c[(i + len / 2) % n];
		}
		sort(sa.begin(), sa.end());
		c[sa[0].index] = 0;
		for (int i = 1; i < n; i++) {
			c[sa[i].index] = c[sa[i - 1].index];
			if (sa[i].first != sa[i - 1].first || sa[i].second != sa[i - 1].second) {
				c[sa[i].index]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << sa[i].index + 1 << "\n";
	}
}
