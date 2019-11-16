#include <bits/stdc++.h>

using namespace std;

string s;
int pi[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = s.size();
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	int d = n - pi[n - 1];
	cout << ((d != n && n % d == 0) ? d : 0) << "\n";
}
