#include <iostream>

using namespace std;

int n, tl, tr, l, r;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		tl += l;
		tr += r;
	}
	cout << tr - tl + 1 << "\n";
}
