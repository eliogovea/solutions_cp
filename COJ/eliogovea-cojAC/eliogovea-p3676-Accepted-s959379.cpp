#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
        cout << "Case " << cas << ": ";
		string n;
		cin >> n;
		reverse(n.begin(), n.end());
		int carry = 0;
		for (int i = 0; i < n.size(); i++) {
			carry += 2 * (n[i] - '0');
			n[i] = '0' + (carry % 10);
			carry /= 10;
		}
		while (carry > 0) {
			n += '0' + (carry % 10);
			carry /= 10;
		}
		if (n.size() == 1) {
            cout << "0";
		}
		for (int i = n.size() - 1; i > 0; i--) {
			cout << n[i];
		}
		if (n[0] != '0') {
			cout << "," << n[0];
		}
		cout << "\n";
	}
}
