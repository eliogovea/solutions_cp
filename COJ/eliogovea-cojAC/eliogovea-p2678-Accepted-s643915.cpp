#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int tc, cont['Z' + 5];
pair<int, char> a[30];
string str;

int main() {
	//freopen("e.in", "r", stdin);
	cin >> tc;
	getline(cin, str);
	while (tc--) {
		getline(cin, str);
		int s = str.size();
		for (int i = 0; i < s; i++)
			cont[str[i]]++;
		for (char i = 'A'; i <= 'Z'; i++)
			a[i - 'A'] = make_pair(cont[i], i);
		sort(a, a + 26);
		if (a[25].first != a[24].first) {
			int sol = a[25].second - 'E';
			if (sol < 0) sol += 26;
			cout << sol << ' ';
			for (int i = 0; i < s; i++) {
        if (str[i] < 'A' || str[i] > 'Z') cout << ' ';
        else {
          char c = 'A' + (str[i] - 'A' - sol + 26) % 26;
          cout << c;
        }
			}
			cout << '\n';
		}
		else cout << "NOT POSSIBLE\n";

		for (int i = 'A'; i <= 'Z'; i++)
			cont[i] = 0;
	}
}
