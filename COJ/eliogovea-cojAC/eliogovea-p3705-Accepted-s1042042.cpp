#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL solve(int n) {
	LL ans = 0;
	for (int i = 1; i < n - 2; i++) {
		ans += (LL)(i * (n - 2 - i));
	}
	ans *= n;
	ans /= 4LL;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cout << solve(n) << "\n";
}
