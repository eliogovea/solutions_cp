#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 2) {
		cout << "1.0\n";
		return 0;
	}

	int low = n + m - 3;

	int answer = 2 * (n - 1);


	for (int g = 0; g <= n - 1 && answer == 2 * (n - 1); g++) {
		for (int e = 0; e <= 1 && g + e <= n - 1 && answer == 2 * (n - 1); e++) {
			bool ok = true;

			{ // max p
				int gg = g;
				int ee = e;
				int pp = n - 1 - gg - ee;

				int curLow = low;

				if (pp >= n - m) {
					curLow += 2;
				} else if (pp + ee >= n - m) {
					curLow++;
				}

				if (2 * gg + ee <= curLow) {
					ok = false;
				}
			}

			{ // max ee
				int l = 0;
				int r = g;
				int v = r;
				while (l <= r) {
					int mid = (l + r) >> 1;
					int ne = 2 * g - 2 * mid;
					if (mid + ne <= n - 1 - e) {
						v = mid;
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}

				int gg = v;
				int ee = e + 2 * g - 2 * v;
				assert(gg + ee <= n - 1);
				int pp = n - 1 - gg - ee;

				int curLow = low;

				if (pp >= n - m) {
					curLow += 2;
				} else if (pp + ee >= n - m) {
					curLow++;
				}

				if (2 * gg + ee <= curLow) {
					ok = false;
				}

			}

			{ // max pp + ee
			
			}

			if (ok) {
				answer = 2 * g + e;
			}

		}
	}

	cout << answer / 2;
	if (answer & 1) {
		cout << ".5";
	} else {
		cout << ".0";
	}
	cout << "\n";
}
