// Problem: pace=1&num=1297
// Verdict: Accepted

#include <iostream>
#include <fstream>

using namespace std;

/// Timus - 1297. Palindrome (97)

string s;
bool dp[1005][1005];

int main() {
	//freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = s.size();
	int pos = 0;
	int len = 1;
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i + 1 < n; i++) {
		dp[i][i + 1] = (s[i] == s[i + 1]);
		if (dp[i][i + 1] && len < 2) {
			pos = i;
			len = 2;
		}
	}

	for (int l = 3; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			dp[i][i + l - 1] = (dp[i + 1][i + l - 1 - 1] && (s[i] == s[i + l - 1]));
			if (dp[i][i + l - 1] && l > len) {
				pos = i;
				len = l;
			}
		}
	}

	for (int i = pos; i < pos + len; i++) {
		cout << s[i];
	}
	cout << "\n";
}