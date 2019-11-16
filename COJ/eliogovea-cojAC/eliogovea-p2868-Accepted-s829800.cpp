#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

const string alph = "ACGT";

const int N = 40;
const int L = 40;

struct node {
	int fail;
	bool fin;
	int next[4];
	node() {
		fail = -1;
		fin = false;
		for (int i = 0; i < 4; i++) {
			next[i] = -1;
		}
	}
} t[N * L];

int sz = 1;

void add(const string &s) {
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		char ch = lower_bound(alph.begin(), alph.end(), s[i]) - alph.begin();
		if (t[cur].next[ch] == -1) {
			t[sz] = node();
			t[cur].next[ch] = sz++;
		}
		cur = t[cur].next[ch];
	}
	t[cur].fin = true;
}

queue<int> Q;

void build() {
	for (int i = 0; i < 4; i++) {
		if (t[0].next[i] == -1) {
			t[0].next[i] = 0;
		} else {
			t[t[0].next[i]].fail = 0;
			Q.push(t[0].next[i]);
		}
	}
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			if (t[cur].next[i] != -1) {
				int next = t[cur].next[i];
				int fail = t[cur].fail;
				while (t[fail].next[i] == -1) {
					fail = t[fail].fail;
				}
				fail = t[fail].next[i];
				t[next].fail = fail;
				t[next].fin |= t[fail].fin;
				Q.push(next);
			}
		}
	}
}

int find_next(int cur, char ch) {
	while (t[cur].next[ch] == -1) {
		cur = t[cur].fail;
	}
	cur = t[cur].next[ch];
	return cur;
}

int n;
string s;
string dna;

int dp[1005][N * L];

int cas = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n && n) {
		t[0] = node();
		sz = 1;
		for (int i = 0; i < n; i++) {
			cin >> s;
			add(s);
		}
		cin >> dna;
		build();
		for (int i = 0; i <= dna.size(); i++) {
			for (int j = 0; j < sz; j++) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < dna.size(); i++) {
			int ch = lower_bound(alph.begin(), alph.end(), dna[i]) - alph.begin();
			for (int j = 0; j < sz; j++) {
				if ((t[j].fin) || (dp[i][j] == -1)) {
					continue;
				}
				for (int k = 0; k < 4; k++) {
					int next = find_next(j, k);
					if (t[next].fin) {
						continue;
					}
					int tmp = dp[i][j] + (ch != k);
					if (dp[i + 1][next] == -1 || tmp < dp[i + 1][next]) {
						dp[i + 1][next] = tmp;
					}
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < sz; i++) {
			if (!t[i].fin && dp[dna.size()][i] != -1 && (ans == -1 || dp[dna.size()][i] < ans)) {
				ans = dp[dna.size()][i];
			}
		}
		cout << "Case " << cas++ << ": " << ans << "\n";
	}
}
