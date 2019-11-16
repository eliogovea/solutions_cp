#include <iostream>
#include <algorithm>
using namespace std;

int tc, n;
string str;

int sol(char tip) {
	int p1 = 0, p2 = 0, c = 0, s = 0, size = str.size();
	while (p2 < size) {
        //cout << p1 << " " << p2 << endl;
		if (str[p2] == tip) p2++;
		else if (c < n) c++, p2++;
		else if (str[p1] == tip) p1++;
		else c--, p1++;
		s = max(s, p2 - p1);
	}
	return s;
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n >> str;
		int s = max(sol('<'), sol('>'));
		reverse(str.begin(), str.end());
		s = max(s, max(sol('<'), sol('>')));
		cout << s << endl;
	}
}
