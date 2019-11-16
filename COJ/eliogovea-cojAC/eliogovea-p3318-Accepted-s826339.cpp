#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	//freopen("dat.txt", "r", stdin);
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		double da = a;
		double db = b;
		double dc = c;
		double vol = 4.0 * M_PI / 3.0 + M_PI * (da + db + dc) + da * db * dc + 2.0 * (da * db + db * dc + dc * da);
		cout << fixed << vol << "\n";
	}
}
