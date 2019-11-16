#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (2 * k + 1 > n) {
		cout << "-1\n";
	} else {
		cout << n * k << "\n";
	}
}