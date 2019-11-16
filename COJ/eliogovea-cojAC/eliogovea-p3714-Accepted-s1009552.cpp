#include <bits/stdc++.h>

using namespace std;

int c[] = {0, 1, 5, 3, 4, 2, 9, 7, 8, 6};
string s;
int val['z' + 5];

int main() {
	while (cin >> s) {
		for (int i = 'a'; i <= 'z'; i++) {
			val[i] = 0;
		}
		int curVal = 1;
		for (int i = 0; i < s.size(); i++) {
			if (val[s[i]] == 0) {
				val[s[i]] = curVal++;
			}
			int x = val[s[i]];
			string tmp;
			while (x) {
				tmp += '0' + c[x % 10];
				x /= 10;
			}
			reverse(tmp.begin(), tmp.end());
			cout << tmp;
		}
		cout << "\n";
	}
}
