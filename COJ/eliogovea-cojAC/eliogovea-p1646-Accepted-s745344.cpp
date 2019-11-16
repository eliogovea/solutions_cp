#include <iostream>

using namespace std;

int n, m, x, s;

int main() {
	while (cin >> m >> n) {
		s = 0;
		while (m--) {
			cin >> x;
			s ^= x;
		}
		if (s) cout << "Vida\n";
		else cout << "Andrea\n";
	}
}