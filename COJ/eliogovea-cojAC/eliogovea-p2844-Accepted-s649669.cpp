#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int sol;
string w, text, aux, s;

int main() {
    ios::sync_with_stdio(false);
    //freopen("e.in", "r", stdin);
	char c = 1;
	cin >> w;
	int sw = w.size();
	getline(cin, aux);
	while (getline(cin, aux)) {
        aux += ' ';
		text += aux;
	}

	s = w + c + text;
	//cout << s << '\n';
	int n = s.size();
	vector<int> pi(n, 0);
	//cout << s[0] << " 0\n";
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
		if (j == sw) sol++;
        //cout << s[i] << ' ' << j << '\n';
	}
	cout << sol << '\n';
}
