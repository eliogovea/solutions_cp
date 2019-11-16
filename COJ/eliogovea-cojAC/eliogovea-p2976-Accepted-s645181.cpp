#include <iostream>

using namespace std;

int n, a[50], e1, e2;

int main() {
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		bool sol = false;
		for (int i = 1; i <= n; i++)
			if (a[i] + a[i] == a[n]) {
				sol = true;
				e1 = i;
				e2 = i + 1;
			}
		if (sol) cout << "Sam stops at position " << e1
		<< " and Ella stops at position " << e2 << ".\n";
		else cout << "No equal partitioning.\n";
	}
}
