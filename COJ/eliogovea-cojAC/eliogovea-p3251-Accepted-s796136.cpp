#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int res = 0;
	bool d10 = false;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '0') {
			d10 = true;
		}
		res = (res + s[i] - '0') % 3;
	}
	if (d10 && (res == 0)) {
		sort(s.begin(), s.end(), greater<char>());
		cout << s << "\n";
	} else {
		cout << "-1\n";
	}
}
