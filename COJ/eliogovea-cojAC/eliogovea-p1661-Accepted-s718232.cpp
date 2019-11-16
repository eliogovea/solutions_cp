#include <iostream>

using namespace std;

long long n, a[55];

int main() {
	a[0] = 1;
	for (int i = 0; i < 50; i++) {
		a[i + 1] += a[i];
		a[i + 2] += a[i];
	}
	while (cin >> n && n) cout << a[n] << "\n";
}