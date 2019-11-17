// Problem: pace=1&num=1079
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 99999;

int a[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	a[0] = 0;
	a[1] = 1;
	for (int i = 1; i <= N; i++) {
		if (i & 1) {
			a[i] = a[i / 2] + a[i / 2 + 1];
		} else {
			a[i] = a[i / 2];
		}
	}
	for (int i = 2; i <= N; i++) {
		if (a[i] < a[i - 1]) {
			a[i] = a[i - 1];
		}
	}
	int n;
	while (cin >> n && n) {
		cout << a[n] << "\n";
	}
}
