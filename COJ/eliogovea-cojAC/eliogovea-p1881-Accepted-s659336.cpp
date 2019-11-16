#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1005;

int tc, n, s, v[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			tmp += v[i];
		}
		if (tmp / 10 > s) cout << "-1\n";
		else if (tmp <= s) cout << "0\n";
		else {
			int lo = 0, hi = 100000, mid, val, sol;
			while (lo + 1 < hi) {
				int mid = (lo + hi) >> 1;
				val = 0;
				for (int i = 0; i < n; i++)
					val += max(v[i] - 10 * mid, v[i] / 10);
				if (val <= s) sol = hi = mid;
				else lo = mid;
			}
			cout << sol << "\n";
		}
	}
}
