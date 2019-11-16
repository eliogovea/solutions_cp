#include <iostream>

using namespace std;

int tc, a['z' + 5], b['z' + 5];
string s;

bool solve(const string &s) {
	for (int i = 'a'; i <= 'z'; i++) b[i] = a[i];
	for (int i = 0; s[i]; i++) {
		if (s[i] == ' ') continue;
		if (b[s[i]] == 0) return false;
		b[s[i]]--;
	}
	return true;
}

int main() {
	cin >> tc;
	for (int i = 'a'; i <= 'z'; i++) cin >> a[i];
	getline(cin, s);
	while (getline(cin, s))
		cout << (solve(s) ? "YES" : "NO") << "\n";
}
