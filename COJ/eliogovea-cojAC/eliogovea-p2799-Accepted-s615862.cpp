#include <iostream>
using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;
	if (a + b + c == 180 && a > 0 && b > 0 && c > 0) {
		if (a == b && b == c) cout << "Equilateral\n";
		else if (a != b && b != c && c != a) cout << "Scalene\n";
		else cout << "Isosceles\n";
	}
	else cout << "Error\n";
}

