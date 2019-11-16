#include <iostream>
#include <algorithm>

using namespace std;

int p, r1, c1, r2, c2;

inline bool check(int x) {
	if (x < 1 || x > 8) return false;
	return true;
}

int main() {
	while (cin >> p >> r1 >> c1 >> r2 >> c2) {
		bool ok = true;
		if (!check(r1) || !check(c1) || !check(r2) || !check(c2))
			ok = false;
		int diff = abs(r1 - r2) + abs(c1 - c2);
		if (diff != 1) ok = false;
		if (!ok) cout << "ERROR\n";
		else cout << 3 - p << "\n";
	}
}
