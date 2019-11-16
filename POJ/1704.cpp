#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000 + 5;

int t;
int n;
int p[N];
int d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++) {
			d[i] = p[i] - p[i - 1] - 1;
		}
		int xorSum = 0;
		for (int i = n; i >= 1; i -= 2) {
			xorSum ^= d[i];
		}
		cout << ((xorSum != 0) ? "Georgia" : "Bob") << " will win\n";
	}
}
