#include <iostream>
#include <fstream>

using namespace std;

int b, a, sol;
int mark['Z' + 5];
string s;

int main() {
	//freopen("e.in", "r", stdin);
	while (cin >> b && b) {
		cin >> s;
		a = sol = 0;
		for (int i = 0; s[i]; i++) {
			if (mark[s[i]] == 1) {
				a--;
				mark[s[i]] = 0;
			}
			else if (mark[s[i]] == 2) {
        sol++;
        mark[s[i]] = 0;
			}
			else if (a < b) {
				a++;
				mark[s[i]] = 1;
			}
			else mark[s[i]] = 2;
		}
		if (sol == 0) cout << "All customers tanned successfully.\n";
		else cout << sol << " customer(s) walked away.\n";
	}
}
