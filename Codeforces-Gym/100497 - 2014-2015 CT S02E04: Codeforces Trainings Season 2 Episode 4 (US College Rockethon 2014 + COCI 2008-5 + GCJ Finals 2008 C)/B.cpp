// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497B

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

string s;

bool ok[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		ok[i] = (s[i] == s[n - 1 - i]);
	}
	set <string> S;
	if (n & 1) {
		int c = n / 2;
		vector <int> first, second;
		for (int i = 0; i < c; i++) {
			if (!ok[i]) {
				first.push_back(i);
				second.push_back(n - 1 - i);
			}
		}
		if (first.size() == 0) {
			S.insert(s);
		} else if (first.size() == 1) {
			if (s[c] == s[second[0]]) {
				swap(s[c], s[first[0]]);
				S.insert(s);
				swap(s[c], s[first[0]]);
			}
			if (s[c] == s[first[0]]) {
				swap(s[c], s[second[0]]);
				S.insert(s);
				swap(s[c], s[second[0]]);
			}
		} else if (first.size() == 2) {
			swap(s[first[0]], s[first[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[first[0]], s[first[1]]);
			swap(s[first[0]], s[second[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[first[0]], s[second[1]]);
			swap(s[second[0]], s[second[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[second[0]], s[second[1]]);
			swap(s[second[0]], s[first[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[second[0]], s[first[1]]);
		}
	} else {
		int c = (n - 1) / 2;
		vector <int> first, second;
		for (int i = 0; i <= c; i++) {
			if (!ok[i]) {
				first.push_back(i);
				second.push_back(n - 1 - i);
			}
		}
		if (first.size() == 0) {
			S.insert(s);
		} else if (first.size() == 2) {
			swap(s[first[0]], s[first[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[first[0]], s[first[1]]);
			swap(s[first[0]], s[second[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[first[0]], s[second[1]]);
			swap(s[second[0]], s[second[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[second[0]], s[second[1]]);
			swap(s[second[0]], s[first[1]]);
			if (s[first[0]] == s[second[0]] && s[first[1]] == s[second[1]]) {
				S.insert(s);
			}
			swap(s[second[0]], s[first[1]]);
		}
	}
	cout << S.size() << "\n";
	for (set <string>::iterator it = S.begin(); it != S.end(); it++) {
		cout << *it << "\n";
	}
}
