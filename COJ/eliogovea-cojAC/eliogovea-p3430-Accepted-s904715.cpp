#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	vector <char> v;
	getline(cin, s);
	for (int i = 0; s[i]; i++) {
		if (s[i] == ')') {
			int pos = v.size() - 1;
			vector <char> tmp;
			while (v.back() != '(') {
				tmp.push_back(v.back());
				v.pop_back();
			}
			v.pop_back();
			for (int i = 0; i < tmp.size(); i++) {
                v.push_back(tmp[i]);
			}
		} else {
            v.push_back(s[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << "\n";
}
