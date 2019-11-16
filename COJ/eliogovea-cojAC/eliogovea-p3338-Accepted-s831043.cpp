#include <bits/stdc++.h>

using namespace std;

int t;
string a, b;

char c['Z' + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	getline(cin, a);
	for (int cas = 1; cas <= t; cas++) {
		getline(cin, a);
		getline(cin, b);
		cout << cas << " ";
		for (int i = 0; b[i]; i++) {
			c['A' + i] = b[i];
		}
		for (int i = 0; a[i]; i++) {
			if (a[i] == ' ') {
				cout << " ";
			} else {
				cout << c[a[i]];
			}
		}
		cout << "\n";
	}
}
