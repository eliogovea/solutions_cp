#include <bits/stdc++.h>

using namespace std;

const int N = 200, L = 100;

struct node {
	int next[27];
	int fin;
	node() {
		fin = -1;
		for (int i = 'a'; i <= 'z'; i++) {
			next[i - 'a'] = -1;
		}
	}
};

node t[10500];

int sz;

void init() {
	for (int i = 0; i < sz; i++) {
		t[i] = node();
	}
}

void add(string &s, int id) {
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		s[i] -= 'a';
		if (t[cur].next[s[i]] == -1) {
			t[cur].next[s[i]] = sz++;
		}
		cur = t[cur].next[s[i]];
	}
	t[cur].fin = id;
}

bool mark[N];

void check(string &s) {
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		s[i] -= 'a';
		if (t[cur].next[s[i]] == -1) {
			return;
		}
		cur = t[cur].next[s[i]];
	}
	if (t[cur].fin != -1) {
		mark[t[cur].fin] = true;
	}
}

string s;
int tc, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		init();
		for (int i = 0; i < n; i++) {
			cin >> s;
			add(s, i);
		}
		for (int i = 0; i < n; i++) {
			mark[i] = false;
		}
		while (k--) {
			int x;
			cin >> x;
			while (x--) {
				cin >> s;
				check(s);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << (mark[i] ? "YES" : "NO");
			if (i + 1 < n) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

