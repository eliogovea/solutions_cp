#include <bits/stdc++.h>

using namespace std;

const int S = 20 * 15 + 10;
const int N = 1005;
const int INF = 1e9;

struct node {
	int fin;
	int next[4];
	int fail;
	node() {
		fin = 0;
		next[0] = next[1] = next[2] = fail = -1;
	}
};

node t[S];
int sz = 1;

const int root = 0;

void add(string &s) {
	int cur = root;
	for (int i = 0; s[i]; i++) {
		s[i] -= 'A';
		if (t[cur].next[s[i]] == -1) {
			t[cur].next[s[i]] = sz++;
		}
		cur = t[cur].next[s[i]];
	}
	t[cur].fin++;
}

void build() {
	queue <int> Q;
	for (int i = 0; i < 3; i++) {
		if (t[root].next[i] == -1) {
			t[root].next[i] = root;
		} else {
			t[t[root].next[i]].fail = root;
			Q.push(t[root].next[i]);
		}
	}
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++) {
			int next = t[cur].next[i];
			if (next != -1) {
				int fail = t[cur].fail;
				while (t[fail].next[i] == -1) {
					fail = t[fail].fail;
				}
				fail = t[fail].next[i];
				t[next].fail = fail;
				t[next].fin += t[fail].fin;
				Q.push(next);
			}
		}
	}
}

int find_next(int cur, int ch) {
	while (t[cur].next[ch] == -1) {
		cur = t[cur].fail;
	}
	cur = t[cur].next[ch];
	return cur;
}

int n, k;
string s;
int dp[N][S];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	while (n--) {
		cin >> s;
		add(s);
	}
	build();
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < sz; j++) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i< k; i++) {
		for (int j = 0; j < sz; j++) {
			for (int l = 0; l < 3; l++) {
				int next = find_next(j, l);
				dp[i + 1][next] = max(dp[i + 1][next], dp[i][j] + t[next].fin);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < sz; i++) {
		ans = max(ans, dp[k][i]);
	}
	cout << ans << "\n";
}
