// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147A

/*
	Problem A. The game of Osho
	ACM International Collegiate Programming Contest,
	Egyptian Collegiate Programming Contest (2016) Arab Academy for Science,
	Technology and Maritime Transport - Alexandria, November 9th, 2016
*/

#include <bits/stdc++.h>

using namespace std;

void check(int base, int limit) {
	vector <int> grundy(limit + 1);
	vector <int> used(limit + 1, -1);
	for (int i = 0; i <= limit; i++) {
		for (int j = 1; j <= i; j *= base) {
			used[grundy[i - j]] = i;
		}
		grundy[i] = 0;
		while (used[grundy[i]] == i) {
			grundy[i]++;
		}
		//cerr << i << " " << grundy[i] << "\n";
		assert(!(base & 1) && grundy[i] == grundy[i % (base + 1)]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("powers.in", "r", stdin);
	// check(4, 1000);
	// parece cumplirse que:
	// si b es par
	// grundy(b, n) = grundy(b, n % (b + 1))
	// grundy(b, b) = 2
	// grundy(b, n) = n & 1 con b < n
	int t;
	cin >> t;
	while (t--) {
		int g;
		cin >> g;
		int xorSum = 0;
		while (g--) {
			int b, n;
			cin >> b >> n;
			int grundy = 0;
			if (b & 1) {
				grundy = n & 1;
			} else {
				n %= b + 1;
				if (n == b) {
					grundy = 2;
				} else {
					grundy = n & 1;
				}
			}
			xorSum ^= grundy;
		}
		cout << ((xorSum != 0) ? "1" : "2") << "\n";
	}
}
