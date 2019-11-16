// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513M

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	vector <vector <int> > c(350), r(350);
	string line;
	int n;
	cin >> n;
	getline(cin, line);
	vector <char> s;
	for (int l = 1; l <= n; l++) {
		getline(cin, line);
		for (int i = 0; i < line.size(); i++) {
			if (('a' <= line[i] && line[i] <= 'z') || (line[i] == '{')) {
				if ('a' <= line[i] && line[i] <= 'z') {
					if (c[line[i]].size() > 0) {
						cout << l << ":" << i + 1 << ": warning: shadowed declaration of " << line[i] << ", the shadowed position is " << r[line[i]].back() << ":" << c[line[i]].back() << "\n";
					}
				}
				s.push_back(line[i]);
				c[line[i]].push_back(i + 1);
				r[line[i]].push_back(l);
			} else if (line[i] == '}') {
				while (s.back() != '{') {
					c[s.back()].pop_back();
					r[s.back()].pop_back();
					s.pop_back();
				}
				s.pop_back();
			}
		}
	}
}
