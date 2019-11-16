// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196E

#include <bits/stdc++.h>

using namespace std;

vector <int> prefixFunction(const string &s) {
	int n = s.size();
	vector <int> pi(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	string s;
	cin >> s;
	int n = s.size();
	int ans = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int l = j - i + 1;
			string ss = s.substr(i, l);
			vector <int> pi = prefixFunction(ss);
			vector <int> dp(n + 1);
			dp[0] = l;
			for (int k = 0, p = 0; k < n; k++) {
				dp[k + 1] = dp[k] + 1;
				while (p > 0 && s[k] != ss[p]) {
					p = pi[p - 1];
				}
				if (s[k] == ss[p]) {
					p++;
				}
				if (p >= l) {
					dp[k + 1] = min(dp[k + 1], dp[k + 1 - l] + 1);
				}
			}
			//cerr << i << " " << j << " " << dp[n] << "\n";
			ans = min(ans, dp[n]);
		}
	}
	cout << ans << "\n";
}
