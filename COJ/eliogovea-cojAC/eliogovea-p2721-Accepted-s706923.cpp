#include <iostream>
#include <algorithm>

using namespace std;

int n, x[105];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	bool ch = true;
	while (ch) {
		ch = false;
		sort(x, x + n);
		for (int i = 1; i < n; i++)
			if (x[i] > x[0]) {
				x[i] -= x[0];
				ch = true;
			}
	}
	cout << n * x[0] << "\n";
}
