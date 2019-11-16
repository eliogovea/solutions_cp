#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s && (s != "END")) {
		int sz = s.size();
		if (s[0] != '-') {
			int sum = 0;
			int t = 2;
			bool ok = false;
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] != '0' && sum >= 2) {
					ok = true;
					s[i]--;
					for (int j = i + 1; j < s.size(); j++) {
                        if (t >= 9) {
                            s[j] = '9';
                            t -= 9;
                        } else {
                            s[j] = '0' + t;
                            t = 0;
                        }
					}
                    break;
				}
				sum += '9' - s[i];
				t += s[i] - '0';
			}
			if (ok) {
				for (int i = (s[0] == '0'); i < s.size(); i++) {
					cout << s[i];
				}
				cout << "\n";
			} else {
				int sum = 1;
				for (int i = 0; i < s.size(); i++) {
					sum += s[i] - '0';
				}

				int c = sum / 9;
				int r = sum % 9;
				cout << "-";
				if (r != 0) {
					cout << r;
				}
				for (int i = 0; i < c; i++) {
					cout << "9";
				}
				cout << "\n";
			}
		} else {
			bool ok = false;
			for (int i = s.size() - 1; i > 0; i--) {
				if (s[i] != '9') {
					ok = true;
					s[i]++;
					break;
				}
			}
			if (ok) {
				cout << s << "\n";
			} else {
                cout << "-1";
                for (int i = 1; i < s.size(); i++) {
                    cout << s[i];
                }
                cout << "\n";
			}
		}

	}
}
