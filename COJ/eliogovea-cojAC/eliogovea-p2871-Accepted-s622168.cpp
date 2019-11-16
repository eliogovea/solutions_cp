#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string str;
int a, b, c;
ll sol;
map<pair<int, int>, ll > m;
pair<int, int> p;

int main() {
	m[make_pair(0, 0)] = 1ll;
	cin >> str;
	for (int i = 0; str[i]; i++) {
		a += str[i] == 'a';
		b += str[i] == 'b';
		c += str[i] == 'c';
		p = make_pair(a - c, b - c);
		sol += m[p]++;
	}
	cout << sol << endl;
}
