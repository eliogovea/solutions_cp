//============================================================================
// Name        : 2051.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string p[25], s, ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i] += "#";
	}
	for (int i = 0; i <= m; i++) p[n] += "#";

	for (int i = 0; i <= n; i++) {
		s.clear();
		for (int j = 0; j <= m; j++) {
			if (p[i][j] == '#') {
				if (s.size() >= 2) ans = min(ans, s);
				s.clear();
				continue;
			}
			s += p[i][j];
		}
	}
	for (int i = 0; i <= m; i++) {
		s.clear();
		for (int j = 0; j <= n; j++) {
			if (p[j][i] == '#') {
				if (s.size() >= 2) ans = min(ans, s);
				s.clear();
				continue;
			}
			s += p[j][i];
		}
	}
	cout << ans << "\n";
}
