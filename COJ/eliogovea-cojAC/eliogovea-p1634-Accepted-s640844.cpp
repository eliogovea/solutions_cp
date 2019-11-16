#include <iostream>
//#include <fstream>

using namespace std;

int tc, n, x, a[1005][15];

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 10; j++) {
				x = (((10 * i) % n) + j) % n;
				cout << x << (j < 9 ? ' ' : '\n');
			}
	}
}
