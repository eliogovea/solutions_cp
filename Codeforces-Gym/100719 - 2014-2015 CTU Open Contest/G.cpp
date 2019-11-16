// 2014-2015 CTU Open Contest
// 100719G

#include <bits/stdc++.h>

using namespace std;

int t;
string s;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> s) {
        if (s == "11") {
            cout << "0\n";
            continue;
        }
		ans.clear();
		reverse(s.begin(), s.end());
		if (s.size() & 1) s += '0';
		s += "000000";
		int pos = 0;
		bool sum = true;
		while (pos < s.size()) {
			string tmp; tmp += s[pos]; tmp += s[pos + 1];
			if (!sum) {
				ans += tmp;
				pos += 2;
				continue;
			}
			if (tmp == "10") {
				ans += "01";
			}
			if (tmp == "01") {
				ans += "11";
				sum = false;
			}
			if (tmp == "11") {
				ans += "00";
				sum = false;
			}
			if (tmp == "00") {
				ans += "10";
				sum = false;
			}
			pos += 2;
		}
		pos = ans.size() - 1;
		while (ans[pos] == '0') pos--;
		for (int i = pos; i >= 0; i--) {
			cout << ans[i];
		}
		cout << "\n";
	}
}
