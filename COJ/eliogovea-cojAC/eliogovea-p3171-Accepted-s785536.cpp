#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

double f[N + 5];

int y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
  f[0] = 0;
	for (int i = 1; i <= N; i++) {
    f[i] = f[i - 1] + log2(i);
	}
	while (cin >> y && y) {
		int bits = 4 * (1 << ((y - 1960) / 10));
		//cout << "bits " << bits << "\n";
		int lo = 0, hi = 1e6;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int need = 1 + (int)f[mid];
			//cout << mid << " " << need << "\n";
			if (need <= bits) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}
