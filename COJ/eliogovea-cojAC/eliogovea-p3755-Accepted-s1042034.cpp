#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;
LL r;
LL a[55];
LL ans[55];

LL egcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL x1, y1;
	LL g = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cas = 1;
	while (true) {
		cin >> n >> r;
		if (n == 0 && r == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			ans[i] = 0;
		}
		LL curG = a[0];
		ans[0] = 1;
		for (int i = 1; i < n; i++) {
			LL x, y;
			curG = egcd(curG, a[i], x, y);
			for (int j = 0; j < i; j++) {
				ans[j] *= x;
			}
			ans[i] = y;
			if (r % curG == 0) {
				break;
			}
		}
		cout << "Case #" << cas++ << ": ";
		if (r % curG == 0) {
			for (int i = 0; i < n; i++) {
				cout << ans[i] * (r / curG);
				if (i + 1 < n) {
					cout << " ";
				}
			}
			cout << "\n";
		} else {
			cout << "Stupid keypad!\n";
		}

	}
}
