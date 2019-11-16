#include <iostream>
#include <fstream>

using namespace std;

int l, n, p, sol;
char d;
string s1 = "The last ant will fall down in ";
string s2 = " seconds.\n";

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	while (cin >> l >> n && (n | l)) {
		sol = -1;
		while (n--) {
			cin >> p >> d;
			if (d == 'L')
				if (sol < p) sol = p;
			if (d == 'R')
				if (sol < l - p) sol = l - p;
		}
		cout << s1 << sol << s2;
	}
}
