#include <iostream>

using namespace std;

bool mark['Z' + 5];
string s;
char sol;

int main() {
	cin >> s;
	for (int i = 0; s[i]; i++) mark[s[i]] = true;
	if (!mark['A']) sol = 'A';
	else if (!mark['C']) sol = 'C';
	else if (!mark['G']) sol = 'G';
	else if (!mark['T']) sol = 'T';
	else sol = 'A';
	cout << sol << "\n";
}
