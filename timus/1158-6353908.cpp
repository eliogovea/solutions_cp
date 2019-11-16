// Problem: pace=1&num=1158
// Verdict: Accepted

// Timus 1158. Censored!

#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int ALPH = 51;

int n, m, p;
string s[N];

struct node {
	bool fin;
	int fail;
	int next[ALPH];
	node() {
		fin = false;
		fail = -1;
		for (int i = 0; i < ALPH; i++) {
			next[i] = -1;
		}
	}
} t[N * N];

int sz = 1;

void add(string &str) {
	int cur = 0;
	for (int i = 0; str[i]; i++) {
		char ch = lower_bound(s[p].begin(), s[p].end(), str[i]) - s[p].begin();
		if (t[cur].next[ch] == -1) {
			t[cur].next[ch] = sz++;
		}
		cur = t[cur].next[ch];
	}
	t[cur].fin = true;
}

queue<int> Q;

// Aho Corasick
void build() {
	for (int i = 0; i < ALPH; i++) {
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
		for (int i = 0; i < n; i++) {
			if (t[cur].next[i] != -1) {
				int fail = t[cur].fail;
				int next = t[cur].next[i];
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

typedef vector<int> BigInteger;

const BigInteger ZERO = vector<int>(1, 0);
const BigInteger ONE = vector<int>(1, 1);

BigInteger operator + (const BigInteger &a, const BigInteger &b) {
	BigInteger res = ZERO;
	int sz = max(a.size(), b.size());
	res.resize(sz);
	int carry = 0;
	for (int i = 0; i < sz; i++) {
		if (i < a.size()) {
			carry += a[i];
		}
		if (i < b.size()) {
			carry += b[i];
		}
		res[i] = carry % 10;
		carry /= 10;
	}
	while (carry) {
		res.push_back(carry % 10);
		carry /= 10;
	}
	return res;
}

void Print(BigInteger &x) {
	for (int i = x.size() - 1; i >= 0; i--) {
		cout << x[i];
	}
	cout << "\n";
}

BigInteger dp[N][N * N];


int ans[100005];
int len = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> m >> p;
	cin >> s[p]; // letras
	sort(s[p].begin(), s[p].end());
	for (int i = 0; i < p; i++) {
		cin >> s[i];
		add(s[i]);
	}
	build();
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < sz; j++) {
			dp[i][j] = ZERO;
		}
	}
	dp[0][0] = ONE;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < sz; j++) {
			if ((!t[j].fin) && (dp[i][j] != ZERO)) {
				for (int k = 0; k < n; k++) {
					int next = find_next(j, k);
					if (!t[next].fin) {
						dp[i + 1][next] = dp[i + 1][next] + dp[i][j];
					}
				}
			}
		}
	}
	BigInteger ans = ZERO;
	for (int i = 0; i < sz; i++) {
		ans = ans + dp[m][i];
	}
	Print(ans);
}
