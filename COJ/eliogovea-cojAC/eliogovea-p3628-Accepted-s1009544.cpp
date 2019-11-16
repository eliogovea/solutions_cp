#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string line;
	while (getline(cin, line)) {
		istringstream in1(line);
		string s;
		string s1;
		while (in1 >> s) {
			s1 += s[0];
		}
		getline(cin, line);
		istringstream in2(line);
		string s2;
		while (in2 >> s) {
			s2 += s[0];
		}
		cout << (s1 == s2 ? "yes" : "no") << "\n";
	}
}
