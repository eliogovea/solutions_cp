#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, int> M;
map<string, int>::iterator it;
string s1;
int re;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (n--) {
		cin >> s1 >> re;
		M[s1] = re;
	}
	while (m--) {
		cin >> s1;
		it = M.find(s1);
		if (it == M.end()) cout << "not found\n";
		else {
			cin >> re;
			if (it->second == re) cout << "ok\n";
			else cout << "wrong\n";
		}
	}
}
