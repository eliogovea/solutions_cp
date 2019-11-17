// Problem: pace=1&num=1517
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int ALPH = 256;

int tc;
int n;
string s;
int p[MAXN], pn[MAXN], c[MAXN], cn[MAXN];
int cnt[ALPH];
int lcp[MAXN], pos[MAXN];

void BuildSuffixArray() {
	n++;
	for (int i = 0; i < ALPH; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}
	for (int i = 1; i < ALPH; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		p[--cnt[s[i]]] = i;
	}
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]]) {
			classes++;
		}
		c[p[i]] = classes - 1;
	}
	for (int h = 0; (1 << h) < n; h++) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) {
				pn[i] += n;
			}
		}
		for (int i = 0; i < classes; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i < classes; i++) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			p[--cnt[c[pn[i]]]] = pn[i];
		}
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			int mid1 = (p[i] + (1 << h)) % n;
			int mid2 = (p[i - 1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) {
				classes++;
			}
			cn[p[i]] = classes - 1;
		}
		for (int i = 0; i < n; i++) {
			c[i] = cn[i];
		}
	}
	for (int i = 1; i < n; i++) {
		p[i - 1] = p[i];
	}
	n--;
}

void BuildLCP() {
	for (int i = 0; i < n; i++) {
		pos[p[i]] = i;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (k > 0) {
			k--;
		}
		if (pos[i] == n - 1) {
			lcp[n - 1] = -1;
			k = 0;
			continue;
		}
		int j = p[pos[i] + 1];
		while (s[i + k] == s[j + k]) {
			k++;
		}
		lcp[pos[i]] = k;
	}
}

int lcs(string &a, string &b, int &beg) {
	s.clear();
	s = a + "#" + b;
	int len = a.size();
	n = s.size();
	BuildSuffixArray();
	BuildLCP();
	int res = 0;
	beg = 0;
	for (int i = 0; i < n - 1; i++) {
		if ((p[i] < len && p[i + 1] > len) || (p[i] > len) && p[i + 1] < len) {
			if (lcp[i] > res) {
				res = lcp[i];
				beg = p[i];
			}
		}
	}
	return res;
}

int len;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> len >> a >> b;
	int beg;
    int L = lcs(a, b, beg);
	cout << s.substr(beg, L) << "\n";
}
