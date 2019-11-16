//============================================================================
// Name        : 3017.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

typedef long long LL;

stack<LL> S;
string line, str;

int main() {
	while (getline(cin, line)) {
		istringstream in(line);
		while (in >> str) {
			int sz = str.size();
			if (sz == 1 && (str[0] < '0' || str[0] > '9')) {
				LL a = S.top(); S.pop();
				LL b = S.top(); S.pop();
				if (str[0] == '+') S.push(a + b);
				else if (str[0] == '*') S.push(a * b);
				else if (str[0] == '-') S.push(b - a);
			} else {
				LL tmp = 0;
				for (int i = 0; i < sz; i++)
					tmp = 10LL * tmp + str[i] - '0';
				S.push(tmp);
			}
		}
		LL ans = S.top(); S.pop();
		cout << ans << "\n";
	}
}
