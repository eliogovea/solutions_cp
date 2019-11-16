// Problem: pace=1&num=1470
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 128;

long long bit[N + 2][N + 2][N + 2];

int n;

void update(int x, int y, int z, int v) {
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= n; j += j & -j) {
			for (int k = z; k <= n; k += k & -k) {
				bit[i][j][k] += v;
			}
		}
	}
}

long long query(int x, int y, int z) {
	long long res = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			for (int k = z; k > 0; k -= k & -k) {
				res += bit[i][j][k];
			}
		}
	}
	return res;
}

int x[2], y[2], z[2], v;
int tipo;

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n;
	while (cin >> tipo) {
		if (tipo == 1) {
			cin >> x[0] >> y[0] >> z[0] >> v;
			update(x[0] + 1, y[0] + 1, z[0] + 1, v);
		} else if (tipo == 2) {
			for (int i = 0; i < 2; i++) {
				cin >> x[i] >> y[i] >> z[i];
				if (i) {
					x[i]++;
					y[i]++;
					z[i]++;
				}
			}
			long long ans = 0;
			for (int i = 0; i < 8; i++) {
				int cnt = 0;
				for (int j = 0; j < 3; j++) {
					if (i & (1 << j)) {
						cnt++;
					}
				}
				if (cnt & 1) {
					ans += query(x[bool(i & 1)], y[bool(i & 2)], z[bool(i & 4)]);
				} else {
					ans -= query(x[bool(i & 1)], y[bool(i & 2)], z[bool(i & 4)]);
				}

			}
			cout << ans << "\n";
		} else {
			break;
		}
	}
}