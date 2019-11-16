#include <bits/stdc++.h>

using namespace std;

vector <vector <long long> > solve(int n, int l) {
	vector <vector <long long> > dp(n + 1, vector <long long> (l + 1, 0));
	dp[n][l] = 1;
	for (int ll = l - 1; ll >= 0; ll--) {
		for (int nn = 0; nn <= n; nn++) {
		    if (nn != n) {
                dp[nn][ll] += dp[nn + 1][ll + 1];
		    }
			dp[nn][ll] += (long long)nn * dp[nn][ll + 1];
		}
	}
	return dp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long k;
	string s;

	cin >> n >> k >> s;

	int len = 0;
	long long sum = 0;
	vector <vector <long long> > dp;
	while (sum < k) {
        len++;
        dp = solve(n, len);
        sum += dp[0][0];
	}

	k = k - (sum - dp[0][0]);

	// cerr << "k: " << k << "\n";
	// cerr << "len: " << len << "\n";

	vector <string> ss(n + 1);
	for (int i = 1; i <= n; i++) {
        ss[i] = s.substr(0, i);
        sort(ss[i].begin(), ss[i].end());
	}

	// for (int i = 0; i <= n; i++) {
        // for (int j = 0;j <= len; j++) {
            // cerr << dp[i][j] << "\t";
        // }
        // cerr << "\n";
	// }

	string answer;

	for (int l = 0, p = 0; l < len; l++) {
        if (p == n) {
            // cerr << l << " " << p << " " << k << " " << answer << " " << ss[p] << "\n";
            for (int i = 0; i < ss[p].size(); i++) {
                int nl = l + 1;
                int np = p;
                if (dp[np][nl] < k) {
                    k -= dp[np][nl];
                } else {
                    answer += ss[p][i];
                    p = np;
                    break;
                }
            }
        } else {
            // cerr << l << " " << p << " " << k << " " << answer << " " << ss[p + 1] << "\n";
            for (int i = 0; i < ss[p + 1].size(); i++) {
                int nl = l + 1;
                int np = (p + 1 <= n && ss[p + 1][i] == s[p]) ? p + 1 : p;
                if (dp[np][nl] < k) {
                    k -= dp[np][nl];
                } else {
                    answer += ss[p + 1][i];
                    p = np;
                    break;
                }
            }
        }
	}

	cout << answer << "\n";
}
