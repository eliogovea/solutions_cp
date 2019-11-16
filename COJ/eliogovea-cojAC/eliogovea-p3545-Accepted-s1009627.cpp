#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << 1LL + (n * (n + 1LL) / 2LL) << "\n";
	}
}