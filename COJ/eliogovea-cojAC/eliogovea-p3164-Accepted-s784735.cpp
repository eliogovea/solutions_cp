#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e9 + 7;

int n;
ll x, y;
ll maxx = -inf, maxy = -inf;
ll minx = inf, miny = inf;
ll dx, dy;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (x > maxx) {
			maxx = x;
		}
		if (x < minx) {
			minx = x;
		}
		if (y > maxy) {
			maxy = y;
		}
		if (y < miny) {
			miny = y;
		}
	}
	dx = maxx - minx;
	dy = maxy - miny;
	if (dy > dx) {
		dx = dy;
	}
	cout << dx * dx << "\n";
}
