//============================================================================
// Name        : 1879.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

int n;
string s;
LL f, m;
map<LL, LL> M[2];
map<LL, LL>::iterator it;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		LL x = 0, y = 0;
		for (LL i = 0; i < 59; i++) {
			if (s[i] == '1') x |= (1LL << i);
			else y |= (1LL << i);
		}
		int g = s[59] - '0';
		it = M[g].find(y);
		if (it != M[g].end()) f += it->second;
		it = M[!g].find(y);
		if (it != M[!g].end()) m += it->second;
		M[g][x]++;
	}
	cout << f << " " << m << "\n";
}
