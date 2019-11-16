#include <bits/stdc++.h>

using namespace std;

int n, x[5005], y[5005];
set<pair<int, int> > S;
set<pair<int, int> >::iterator it;

// (x, y) rota 90 hacia la derecha -> (y, -x)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (ok) {
			continue;
		}
		for (int j = 0; j < i; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dx == 0 && dy == 0) {
				continue;
			}
			int g = __gcd(abs(dx), abs(dy));
			dx /= g;
			dy /= g;
			if (dx < 0 || (dx == 0 && dy < 0)) {
				dx *= -1;
				dy *= -1;
			}
			int ndx = dy;
			int ndy = -dx;
			if (ndx < 0 || (ndx == 0 && ndy < 0)) {
				ndx *= -1;
				ndy *= -1;
			}
			if (S.find(make_pair(ndx, ndy)) != S.end()) {
				ok = true;
				break;
			}
			S.insert(make_pair(dx, dy));
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
}
