#include <bits/stdc++.h>

using namespace std;

int t;
string s;

const string v = "AHIMOTUVWXY";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		bool ok = true;
		for (int i = 0; i < s.size(); i++) {
            bool valid = false;
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == s[i]) {
                    valid = true;
                }
            }
            if (!valid) {
                ok = false;
                break;
            }
		}
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}
