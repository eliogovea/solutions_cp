#include <iostream>
using namespace std;

double x, y;

int main() {
	while (cin >> x >> y) {
		if (x == 0 || y == 0) cout << "AXIS\n";
		else if (x > 0 && y > 0) cout << "Q1\n";
		else if (x < 0 && y > 0) cout << "Q2\n";
		else if (x < 0 && y < 0) cout << "Q3\n";
		else cout << "Q4\n";
		if (x == 0 && y == 0) break;
	}
}
