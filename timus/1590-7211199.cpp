// Problem: pace=1&num=1590
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int MAXS = 2 * 5000 + 1;

int length[MAXS + 1];
map <char, int> next[MAXS + 1];
int suffixLink[MAXS + 1];

int size;
int last;

int getNew(int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = map <char, int> ();
	suffixLink[now] = -1;
	return now;
}

int getClone(int from, int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = next[from];
	suffixLink[now] = suffixLink[from];
	return now;
}

void init() {
	size = 0;
	last = getNew(0);
}

void add(int c) {
	int p = last;
	int cur = getNew(length[p] + 1);
	while (p != -1 && next[p].find(c) == next[p].end()) {
		next[p][c] = cur;
		p = suffixLink[p];
	}
	if (p == -1) {
		suffixLink[cur] = 0;
	} else {
		int q = next[p][c];
		if (length[p] + 1 == length[q]) {
			suffixLink[cur] = q;
		} else {
			int clone = getClone(q, length[p] + 1);
			suffixLink[q] = clone;
			suffixLink[cur] = clone;
			while (p != -1 && next[p][c] == q) {
				next[p][c] = clone;
				p = suffixLink[p];
			}
		}
	}
	last = cur;
}

bool visited[MAXS];
int DP[MAXS];

int dfs(int u) {
	if (visited[u]) {
		return DP[u];
	}
	visited[u] = true;
	DP[u] = 1;
	for (map <char, int> :: iterator it = next[u].begin(); it != next[u].end(); it++) {
		DP[u] += dfs(it->second);
	}
	return DP[u];
}

int t;
int n, k;
string s;

void solve() {
	cin >> s;
	init();
	for (int i = 0; i < s.size(); i++) {
		add(s[i]);
	}
	cout << dfs(0) - 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
