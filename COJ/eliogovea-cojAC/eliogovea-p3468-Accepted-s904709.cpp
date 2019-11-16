#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map <string, int> M;
map <string, int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> s;
		sort(s.begin(), s.end());
		it = M.find(s);
		if (it == M.end()) {
			cout << "0\n";
			M[s] = 1;
		} else {
			cout << it->second << "\n";
			it->second++;
		}
	}
}
