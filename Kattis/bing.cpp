#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
const int L = 32;

struct node {
	int cnt;
	int next['z' - 'a' + 1];
	node() {
		cnt = 0;
		for (char i = 'a'; i <= 'z'; i++) {
			next[i - 'a'] = -1;
		}
	}
};

const int root = 0;

int sz = 1;
node t[N * L];

int add(const string &s) {
	int n = s.size();
	int now = root;
	for (int i = 0; i < n; i++) {
		int ch = s[i] - 'a';
		if (t[now].next[ch] == -1) {
			t[now].next[ch] = sz++;
		}
		now = t[now].next[ch];
		t[now].cnt++;
	}
	return t[now].cnt - 1;
}

int n;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> s;
		int ans = add(s);
		cout << ans << "\n";
	}
}
