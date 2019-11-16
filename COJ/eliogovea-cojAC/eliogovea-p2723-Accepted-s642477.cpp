#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int v, n, a[1005], sol;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> v >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (n < 3) return cout << "0\n", 0;
	else {
		int s = a[0] + a[1];
		for (int i = 2; i < n; i++) {
			if (s + a[i] <= v) sol++;
		}
		if (sol) sol += 2;
		cout << sol << '\n';
	}
}
