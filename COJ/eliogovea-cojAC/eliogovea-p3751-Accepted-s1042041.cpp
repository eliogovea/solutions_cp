#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int ALPH = 256;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int INV2 = power(2, MOD - 2);

inline int c2(int n) {
	if (n < 2) {
		return 0;
	}
	return mul(n, mul(n - 1, INV2));
}

int tc;
int k;
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
		if (pos[i] == 0) {
			lcp[0] = 0;
			k = 0;
			continue;
		}
		int j = p[pos[i] - 1];
		while (s[i + k] == s[j + k]) {
			k++;
		}
		lcp[pos[i]] = k;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		cin >> s >> k;
		n = s.size();
		BuildSuffixArray();
		BuildLCP();
        int ans = 0;
        for (int i = 0, c = 0; i <= n; i++) {
            if (i == n || lcp[i] < k || c < 0) {
                add(ans, c2(c));
                c = n - p[i] - (k - 1);
            } else {
                add(c, n - p[i] - (k - 1));
            }
        }

        cout << "Case #" << cas << ": " << ans << "\n";
	}
}
