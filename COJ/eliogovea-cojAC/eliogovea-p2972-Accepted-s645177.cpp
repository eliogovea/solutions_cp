#include <iostream>

using namespace std;

int n;

int main() {
	while (cin >> n) {
		int x = 1e9 - 5;
		cout << x;
		for (int i = n; i > 1; i--) {
			x -= i;
			cout << ' ' << x;
		}
		cout << '\n';
	}
}
