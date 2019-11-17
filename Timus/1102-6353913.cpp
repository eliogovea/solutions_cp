// Problem: pace=1&num=1102
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 100;

struct node {
	bool fin;
	int next[26];
} T[N];

int cnt = 1;

void add(const string &s) {
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		char c = s[i] - 'a';
		if (T[cur].next[c] == 0) {
			T[cur].next[c] = cnt++;
		}
		cur = T[cur].next[c];
	}
	T[cur].fin = true;
}

int t;
string s;
bool dp[10000005];

int main() {
	add("puton");
	add("out");
	add("output");
	add("in");
	add("input");
	add("one");
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> s;
		int n = s.size();
		for (int i = 0; i <= n; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			if (!dp[i]) {
				continue;
			}
			int cur = 0;
			for (int j = i; j < n; j++) {
				if (T[cur].next[s[j] - 'a'] == 0) {
					break;
				}
				cur = T[cur].next[s[j] - 'a'];
				if (T[cur].fin) {
					dp[j + 1] = true;
				}
			}
		}
		cout << (dp[n] ? "YES" : "NO") << "\n";
	}
}