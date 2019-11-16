#include <bits/stdc++.h>

using namespace std;

int a, c, m, x;
int pos[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> a >> c >> m >> x) {
		for (int i = 0; i < m; i++) {
			pos[i] = -1;
		}
		int curPos = 0;
		do {
			pos[x] = curPos++;
			x = (a * x + c) % m;
			if (pos[x] != -1) {
				break;
			}
		} while (true);
		int t = 0;
		int s = 0;
		int r = 0;
		for (int i = 0; i < m; i++) {
			if (pos[i] != -1) {
				t++;
				if (pos[i] < pos[x]) {
					s++;
				} else {
					r++;
				}
			}
		}
		cout << (t == m ? "YES" : "NO") << " " << t << " " << s << " " << r << "\n";
	}
}
