#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int g = __gcd(a, b);
		cout << a * b / (g * g) << "\n";
	}
}
