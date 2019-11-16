#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	int n, m;
	string s;
	cin >> n >> m;
	int maxx = -1;
	int maxy = -1;
	int minx = n;
	int miny = m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				if (i > maxx) {
					maxx = i;
				}
				if (i < minx) {
					minx = i;
				}
				if (j > maxy) {
					maxy = j;
				}
				if (j < miny) {
					miny = j;
				}
			}
		}
	}
	if (maxx == -1) {
		cout << "0\n";
	} else {
		int dx = maxx - minx + 1;
		int dy = maxy - miny + 1;
		//cout << dx << " " << dy << "\n";
		cout << 2 * (dx + dy) << "\n";
	}
}
