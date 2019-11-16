// Problem: pace=1&num=1354
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int pi[20005];

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	s2 += "#";
	s2 += s1;
	int n = s2.size();
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s2[i] != s2[j]) {
			j = pi[j - 1];
		}
		if (s2[i] == s2[j]) {
			j++;
		}
		pi[i] = j;
	}
	int cnt = pi[n - 1];
	while (cnt == s1.size()) {
		cnt = pi[cnt - 1];
	}
	for (int i = 0; i < s1.size() - cnt; i++) {
		cout << s1[i];
	}
	for (int i = s1.size() - cnt; i < s1.size(); i++) {
		cout << s1[i];
	}
	for (int i = s1.size() - cnt - 1; i >= 0; i--) {
		cout << s1[i];
	}
	cout << "\n";
}
