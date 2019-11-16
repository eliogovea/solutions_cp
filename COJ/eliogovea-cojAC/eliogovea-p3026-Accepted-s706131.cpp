#include <iostream>

using namespace std;

int n, x, y, maxx, maxy, minx, miny, l;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (i == 0) {
			maxx = minx = x;
			maxy = miny = y;
		} else {
			if (x > maxx) maxx = x;
			if (x < minx) minx = x;
			if (y > maxy) maxy = y;
			if (y < miny) miny = y;
		}
	}
	l = maxx - minx;
	if (l < maxy - miny) l = maxy - miny;
	cout << l * l << "\n";
}
