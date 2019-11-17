#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		long long u, v;
		cin >> u >> v;
		cout << (u + v) * (u + v + 1LL) / 2LL + (u + 1LL) << "\n";
	}
}
