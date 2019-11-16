#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		int xorSum = 0;
		while (n--) {
			int x;
			cin >> x;
			xorSum ^= x;
		}
		cout << ((xorSum != 0) ? "Yes" : "No") << "\n";
	}
}
