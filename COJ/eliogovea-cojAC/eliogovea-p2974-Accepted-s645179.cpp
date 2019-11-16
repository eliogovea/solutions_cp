#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, cas, m['Z' + 5];
string str, a[25];


bool cmp(const string &a, const string &b) {
	for (int i = 0; a[i] && b[i]; i++)
		if (a[i] != b[i]) return m[a[i]] < m[b[i]];
	return a.size() < b.size();
}

int main() {
	//freopen("e.in", "r", stdin);
	while (cin >> n && n) {
		cin >> str;
		for (int i = 0; str[i]; i++)
			m[str[i]] = i;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, cmp);
		cout << "year " << ++cas << '\n';
		for (int i = 0; i < n; i++)
			cout << a[i] << '\n';
	}
}
