#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int x[100005], y[100005];

void mini(int &a, int b) {
	if (b < a) {
		a = b;
	}
}

void maxi(int &a, int b) {
	if (b > a) {
		a = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int minx = 1e9 + 5;
		int miny = 1e9 + 5;
		int maxx = -1e9 - 5;
		int maxy = -1e9 - 5;
		int left, right, down, up;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			mini(minx, x[i]);
			mini(miny, y[i]);
			maxi(maxx, x[i]);
			maxi(maxy, y[i]);
			if (x[i] == minx) {
				left = i;
			}
			if (x[i] == maxx) {
				right = i;
			}
			if (y[i] == miny) {
				down = i;
			}
			if (y[i] == maxy) {
				up = i;
			}
		}
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (x[i] == minx && y[i] == miny) {
				cout << "1\n" << i + 1 << " NE\n";
				ok = true;
			} else if (x[i] == minx && y[i] == maxy) {
				cout << "1\n" << i + 1 << " SE\n";
				ok = true;
			} else if (x[i] == maxx && y[i] == miny) {
				cout << "1\n" << i + 1 << " NW\n";
				ok = true;
			} else if (x[i] == maxx && y[i] == maxy) {
				cout  << "1\n" << i + 1 << " SW\n";
				ok = true;
			}
			if (ok) {
                break;
			}
		}
		if (ok) {
			continue;
		}
		if (y[left] < y[right]) {
			cout << "2\n";
			cout << left + 1 << " NE\n";
			cout << right + 1 << " SW\n";
		} else {
			cout << "2\n";
			cout << left + 1 << " SE\n";
			cout << right + 1 << " NW\n";
		}
	}
}

