#include <bits/stdc++.h>

using namespace std;

int tc, n;
int x, s, mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		s = 0;
		mx = -1;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (mx == -1 || x > mx) {
				mx = x;
			}
			s += x;
		}
		cout << s - mx << "\n";
	}
}

