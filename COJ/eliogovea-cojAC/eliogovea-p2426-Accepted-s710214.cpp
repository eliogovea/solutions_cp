#include <iostream>
#include <map>
#include <fstream>
#include <queue>

using namespace std;

int tc;

string ini, fin, s;
map<string, int> M;
map<string, int>::iterator it;
queue<string> Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		cin >> ini >> fin;
		M.clear();
		while (!Q.empty()) Q.pop();
		M[ini] = 0;
		Q.push(ini);
		while (!Q.empty()) {
			s = Q.front(); Q.pop();
			if (s == fin) break;
			int v = M[s] + 1;
			//cout << s1 << " " << M[s1] << "\n";
			for (int i = 0; i < 8; i++) {
				if (s[i] == 'B' || s[i] == 'R') {
					if (i + 1 < 8 && s[i + 1] == '.') {
						swap(s[i], s[i + 1]);
						if (M.find(s) == M.end() || M[s] > v) {
							M[s] = v;
							Q.push(s);
						}
						swap(s[i], s[i + 1]);
					}
					if (i + 2 < 8 && (s[i + 1] == 'R' || s[i + 1] == 'G' || s[i + 1] == 'B') && s[i + 2] == '.') {
						swap(s[i], s[i + 2]);
						if (M.find(s) == M.end() || M[s] > v) {
							M[s] = v;
							Q.push(s);
						}
						swap(s[i], s[i + 2]);
					}
				}
				if (s[i] == 'G' || s[i] == 'R') {
					if (i > 0 && s[i - 1] == '.') {
						swap(s[i], s[i - 1]);
						if (M.find(s) == M.end() || M[s] > v) {
							M[s] = v;
							Q.push(s);
						}
						swap(s[i], s[i - 1]);
					}
					if (i > 1 && (s[i - 1] == 'G' || s[i - 1] == 'R' || s[i - 1] == 'B') && s[i - 2] == '.') {
						swap(s[i], s[i - 2]);
						if (M.find(s) == M.end() || M[s] > v) {
							M[s] = v;
							Q.push(s);
						}
						swap(s[i], s[i - 2]);
					}
				}
			}
		}
		cout << "Case " << cas << ": ";
		it = M.find(fin);
		if (it == M.end()) cout << "impossible\n";
		else cout << it->second << "\n";
	}
}
