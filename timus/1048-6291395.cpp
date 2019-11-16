// Problem: pace=1&num=1048
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
short a[N], b[N];
short ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		carry += a[i] + b[i];
		ans[i] = carry % 10;
		carry /= 10;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}
	cout << "\n";
}
