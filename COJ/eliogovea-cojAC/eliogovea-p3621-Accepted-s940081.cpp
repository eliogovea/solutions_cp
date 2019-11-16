#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int t;

void solve(LL x1, LL y1, LL r1, LL x2, LL y2, LL r2) {
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		cout << "SAME\n";
		return;
	}
	LL dx = x1 - x2;
	LL dy = y1 - y2;
	LL d2 = dx * dx + dy * dy;
	if (d2 == r1 * r1 + r2 * r2 + 2LL * r1 * r2) {
		cout << "TANGENT EXT\n";
		return;
	}
	if (d2 == r1 * r1 + r2 * r2 - 2LL * r1 * r2) {
		cout << "TANGENT INT\n";
		return;
	}
	if (d2 > r1 * r1 + r2 * r2 + 2LL * r1 * r2) {
		cout << "EXT\n";
		return;
	}
	if (d2 < r1 * r1 && d2 < r1 * r1 + r2 * r2 - 2LL * r1 * r2) {
		cout << "INT\n";
		return;
	}
	if (d2 < r2 * r2 && d2 < r1 * r1 + r2 * r2 - 2LL * r1 * r2) {
        cout << "INT\n";
        return;
	}
	cout << "SEC\n";
	return;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	LL x1, x2, y1, y2, r1, r2;
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		solve(x1, y1, r1, x2, y2, r2);
	}
}
