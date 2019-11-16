// Problem: pace=1&num=1635
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 4005;

string s;
int n;
bool pal[N][N];
int dp[N];
int trace[N];
vector<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		pal[i][i] = true;
	}
	for (int i = 1; i < n; i++) {
		pal[i][i + 1] = s[i - 1] == s[i];
	}
	for (int l = 3; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			pal[i][i + l - 1] = pal[i + 1][i + l - 1 - 1] && (s[i - 1] == s[i + l - 1 - 1]);
		}
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if (pal[j][i] && (dp[i] == -1 || dp[j - 1] + 1 < dp[i])) {
				dp[i] = dp[j - 1] + 1;
				trace[i] = j - 1;
			}
		}
	}
	int x = n;
	while (x != 0) {
		string y;
		for (int i = trace[x]; i < x; i++) {
			y += s[i];
		}
		x = trace[x];
		ans.push_back(y);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}
