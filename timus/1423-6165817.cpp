// Problem: pace=1&num=1423
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
string a, b, s;
int pi[1000000];

int solve(string &a, string &b) {
	s = a;
	s += (char)(11);
	s += b;
	s += b;
	//cout << s << "\n";
	int n = s.size();
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
		if (i > a.size() && j == a.size()) {
			return i - a.size() - a.size();
		}
	}
	return 1e9;
}

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n >> a >> b;
	int sa = a.size();
	int sb = b.size();
	if (sa != sb) {
		cout << "-1\n";
		return 0;
	}
	int ans = solve(a, b);
	if (ans == 1e9) {
		ans = -1;
	}
	cout << ans << "\n";
}