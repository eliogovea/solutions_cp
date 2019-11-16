#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int solve(long long n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2 || n == 3) {
		return 1;
	}
	if (n % 3 == 0) {
		return 1 + solve(n / 3);
	}
	return 1 + max(solve(n / 3), solve(n / 3 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	long long n;
	cin >> n;
	cout << solve(n) << "\n";
}
