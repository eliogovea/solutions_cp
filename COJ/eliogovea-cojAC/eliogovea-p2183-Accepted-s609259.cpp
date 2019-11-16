#include <iostream>
using namespace std;

int n;
string s;

int main() {
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		int even = 0, odd = 0;
		for (int i = 0; s[i]; i++)
			if (s[i] & 1) odd++;
			else even++;
		if (even > odd) cout << "Even" << endl;
		else cout << "Odd" << endl;
	}
}
