#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

bool solve(int x) {
	for (int i = 0; a[i]; i++) {
		if (x == 1 && a[i] == b[i]) return false;
		if (x == 0 && a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n >> a >> b;
	n &= 1;
	if (solve(n)) cout << "Deletion succeeded\n";
	else cout << "Deletion failed\n";
}
