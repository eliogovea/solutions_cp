#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	string s;
	cin >> s;
	int h = 10 * (s[0] - '0') + (s[1] - '0');
	if (s[8] == 'P') {
	    if (h != 12) {
            h += 12;
	    }
	} else {
        if (h == 12) {
            h = 0;
        }
	}
	if (h < 10) {
		cout << "0";
	}
	cout << h << s.substr(2, 6) << "\n";
}
