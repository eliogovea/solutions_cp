#include <iostream>
#include <fstream>

using namespace std;

int N;
string line, s;

int main() {
	//freopen("e.in", "r", stdin);
	cin >> N;
	getline(cin, line);
	while (N--) {
		getline(cin, line);
		for (int i = 0; line[i]; ) {
			if (line[i] == ' ') {
				cout << line[i];
				i++;
				continue;
			}
			s.clear();
			while (line[i] && line[i] != ' ')
				s += line[i++];
			int j = s.size() - 1;
			while (j >= 0 && (s[j] == 'S' || s[j] == 's')) j--;
			for (int k = 0; k <= j; k++) {
				if (s[k] >= 'a' && s[k] <= 'z')
					s[k] += 'A' - 'a';
				cout << s[k];
			}
		}
		cout << "\n";
	}
}
