// Problem: pace=1&num=1014
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 0) {
        cout << "10\n";
        return 0;
	}
	if (n == 1) {
        cout << "1\n";
        return 0;
	}
	for (int i = 9; i >= 2; i--) {
		while (n % i == 0) {
			ans += '0' + i;
			n /= i;
		}
	}
	if (n > 1) {
		cout << "-1\n";
	} else {
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
}
