//============================================================================
// Name        : Contest2.cpp
// Author      : sUrPRise
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

string s;
int pi[1000005];

int main() {
	//freopen("dat.txt", "r", stdin);
	while (cin >> s) {
		if (s[0] == '.') {
			break;
		}
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
		}
		int k = n - pi[n - 1];
		int ans = (n % k) ? 1 : n / k;
		cout << ans << "\n";
	}
}
