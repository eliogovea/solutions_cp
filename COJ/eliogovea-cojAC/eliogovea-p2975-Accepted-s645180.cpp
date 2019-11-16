#include <iostream>
#include <algorithm>

using namespace std;

int n, p, a[5], id, b[5], idb;

int main() {
	while (cin >> n && n) {
		int x;
		cin >> x;
		p = x;
		id = 0;
		if (p > n / 2) p = n + 1 - p;
		a[id++] = p;
		a[id++] = n + 1 - p;
		if (p & 1) p++;
		else p--;
		a[id++] = p;
		a[id++] = n + 1 - p;
		sort(a, a + 4);
		idb = 0;
		for (int i = 0; i < 4; i++)
			if (a[i] != x) b[idb++] = a[i];
		for (int i = 0; i < 3; i++) {
			cout << b[i];
			if (i < 2) cout << ' ';
			else cout << '\n';
		}
	}
}
