// Problem: pace=1&num=1104
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int get(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 10 + c - 'A';
}

string s;
int a[1000005];

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> s;
	int mx = 0;
	for (int i = 0; s[i]; i++) {
		a[i] = get(s[i]);
		if (a[i] > mx) {
			mx = a[i];
		}
	}
	bool ok = false;
	int ans;
	if (mx + 1 < 2) {
		mx = 1;
	}
	for (int i = mx + 1; i <= 36; i++) {
		int rem = 0;
		for (int j = 0; s[j]; j++) {
			rem = (i * rem + a[j]) % (i - 1);
		}
		if (rem == 0) {
			ok = true;
			ans = i;
			break;
		}
	}
	if (!ok) {
		cout << "No solution.\n";
	} else {
		cout << ans << "\n";
	}
}
