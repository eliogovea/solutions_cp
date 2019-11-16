#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <list>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

int m, s;



string find_max(int m, int s) {
	string ret;
	while (s >= 9) {
		ret += '9';
		s -= 9;
	}
	if (s != 0) ret += '0' + s;
	int sz = ret.size();
	if (sz > m) return "-1";
	while (ret.size() < m) ret += '0';
	return ret;
}

string find_min(int m, int s) {
	for (int i = 1; i <= 9; i++) {
		string tmp = find_max(m - 1, s - i);
		if (tmp == "-1") continue;
		tmp += ('0' + i);
		reverse(tmp.begin(), tmp.end());
		return tmp;
	}
	return "-1";
}

int main() {
	cin >> m >> s;
	if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }
    if (9 * m < s) {
        cout << "-1 -1\n";
        return 0;
    }
    if (m > 1 && s == 0) {
        cout << "-1 -1\n";
        return 0;
    }
	string a = find_max(m, s);
	string b = find_min(m, s);
	if (a == "-1" || b == "-1") cout << "-1 -1\n";
	else cout << b << " " << a << "\n";
	return 0;
}