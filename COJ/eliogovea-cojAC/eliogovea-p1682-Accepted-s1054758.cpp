#include <bits/stdc++.h>

using namespace std;

const int N = 10 * 1000;

int t, n, v;

int grundy[N + 5];
int used[N + 5];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	grundy[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int c = 1; c <= 3; c++) {
			if (c <= i) {
				for (int x = 0; x <= i - c - x; x++) {
					used[grundy[x] ^ grundy[i - c - x]] = i;
				}
			}
		}
		grundy[i] = 0;
		while (used[grundy[i]] == i) {
			grundy[i]++;
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		int xorSum = 0;
		while (n--) {
			cin >> v;
			xorSum ^= grundy[v];
		}
		cout << ((xorSum != 0) ? "MIRKO" : "SLAVKO") << "\n";
	}
}
