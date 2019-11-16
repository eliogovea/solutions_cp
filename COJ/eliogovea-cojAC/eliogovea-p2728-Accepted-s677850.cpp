//============================================================================
// Name        : 2728.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

const int MAXN = 100005;

LL tc, n, a[MAXN], dp[20][MAXN], Log[MAXN], ans;
set<LL> S[MAXN];
set<LL>::iterator it;

void build() {
	for (int i = 1; (1 << i) - 1 <= n; i++)
		for (int j = 1 << i; j <= n; j++) {
			dp[i][j] = __gcd(dp[i - 1][j], dp[i - 1][j - (1 << (i - 1))]);
			S[j].insert(dp[i][j]);
		}
}

inline LL query(int lo, int hi) {
	int l = Log[hi - lo + 1];
	return __gcd(dp[l][hi], dp[l][lo + (1 << l) - 1]);
}

int main() {
	Log[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		Log[i] = Log[i / 2LL] + 1LL;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			S[i].clear();
			cin >> a[i];
			dp[0][i] = a[i];
			S[i].insert(a[i]);
		}
		build();
		for (int i = 1; i <= n; i++)
			for (it = S[i].begin(); it != S[i].end(); it++) {
				LL x = *it;
				int lo = 1, hi = i, mid;
				LL fmid;
				while (lo < hi) {
					mid = (lo + hi) >> 1;
					fmid = query(mid, i);
					if (fmid >= x) hi = mid;
					else lo = mid + 1;
				}
				LL v = x * (LL)(i - hi + 1LL);
				if (v > ans) ans = v;
			}
		cout << ans << "\n";
	}
}
