// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494K

#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

inline void add(int &a, int b, int MOD) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b, int MOD) {
	return (long long)a * b % MOD;
}

const int N = 30000;

const int BASE1 = 37;
const int BASE2 = 41;

int POW1[N + 5];
int POW2[N + 5];

int HASH11[N + 5];
int HASH12[N + 5];
int HASH21[N + 5];
int HASH22[N + 5];

int n;
char a[N + 5];
char b[N + 5];
int anssz;
char ans[N + 5];

inline int val(char ch) {
	return ch - 'A' + 1;
}

inline int get(int * HASH, int * POW, int s, int e, const int MOD) {
	int x = HASH[e];
	int y = mul(HASH[s], POW[e - s], MOD);
	add(x, MOD - y, MOD);
	return x;
}

int lcp(int x, int y) {
	int lo = 0;
	int hi = min(n - x, n - y);
	int res = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int h11 = get(HASH11, POW1, x, x + mid, MOD1);
		int h12 = get(HASH12, POW2, x, x + mid, MOD2);
		int h21 = get(HASH21, POW1, y, y + mid, MOD1);
		int h22 = get(HASH22, POW2, y, y + mid, MOD2);
		if (h11 == h21 && h12 == h22) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[n - 1 - i] = a[i];
	}

	POW1[0] = POW2[0] = 1;

	for (int i = 1; i <= n; i++) {
		POW1[i] = mul(POW1[i - 1], BASE1, MOD1);
		POW2[i] = mul(POW2[i - 1], BASE2, MOD2);
	}

	for (int i = 1; i <= n; i++) {
		HASH11[i] = mul(HASH11[i - 1], BASE1, MOD1); add(HASH11[i], val(a[i - 1]), MOD1);
		HASH12[i] = mul(HASH12[i - 1], BASE2, MOD2); add(HASH12[i], val(a[i - 1]), MOD2);
		HASH21[i] = mul(HASH21[i - 1], BASE1, MOD1); add(HASH21[i], val(b[i - 1]), MOD1);
		HASH22[i] = mul(HASH22[i - 1], BASE2, MOD2); add(HASH22[i], val(b[i - 1]), MOD2);
	}

	int x = 0;
	int y = 0;

	for (int i = 0; i < n; i++) {
		int _lcp = lcp(x, y);
		if (a[x + _lcp] < b[y + _lcp]) {
			ans[anssz++] = a[x];
			x++;
		} else {
			ans[anssz++] = b[y];
			y++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i % 80 == 79) {
			cout << "\n";
		}
	}
	if (anssz % 80) {
		cout << "\n";
	}

}
