#include <bits/stdc++.h>

using namespace std;

int n;
string s;

set<string> S;
set<string>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	n = 2 * n - 1;
	while (n--) {
		cin >> s;
		it = S.find(s);
		if (it != S.end()) {
			S.erase(it);
		} else {
			S.insert(s);
		}
	}
	cout << *S.begin() << "\n";
}
