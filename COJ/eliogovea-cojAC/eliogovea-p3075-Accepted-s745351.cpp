#include <iostream>
#include <cmath>

using namespace std;

double r;

int main() {
	cin >> r;
	cout.precision(6);
	cout << fixed << M_PI * r * r << "\n" << fixed << 2.0 * r * r << "\n";
}
