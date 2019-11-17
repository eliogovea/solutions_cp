// Problem: pace=1&num=1180
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

void check(int base, int limit) {
	vector <int> grundy(limit + 1);
	vector <int> used(limit + 1, -1);
	for (int i = 0; i <= limit; i++) {
		for (int j = 1; j <= i; j *= base) {
			used[grundy[i - j]] = i;
		}
		grundy[i] = 0;
		while (used[grundy[i]] == i) {
			grundy[i]++;
		}
		cout << i << " " << grundy[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int r = 0;
	for (int i = 0; i < s.size(); i++) {
		r = (10 * r + (s[i] - '0')) % 3;
	}
	if (r == 0) {
		cout << "2\n";
	} else {
		cout << "1\n" << r << "\n";
	}
}
