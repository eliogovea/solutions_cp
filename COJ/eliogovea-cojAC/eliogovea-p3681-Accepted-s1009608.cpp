#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 1000000;
	const int INF = 1e9;
	vector <bool> sieve(N + 1, false);
	sieve[0] = sieve[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = true;
			}
		}
	}
	vector <int> primes;
	for (int i = 0; i <= N; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
		}
	}
	vector <vector <int> > sparseTable;
	vector <int> lg(primes.size() + 1);
	lg[1] = 0;
	for (int i = 2; i <= primes.size(); i++) {
		lg[i] = lg[i / 2] + 1;
	}
	sparseTable.push_back(vector <int> (primes.size(), INF));
	for (int i = 2; i < primes.size(); i++) {
		sparseTable[0][i] = primes[i] - primes[i - 2] + 1;
	}
	for (int i = 1; (1 << i) <= primes.size(); i++) {
		sparseTable.push_back(vector <int> (primes.size() - (1 << i) + 1));
		for (int j = 0; j + (1 << i) - 1 < primes.size(); j++) {
			sparseTable[i][j] = min(sparseTable[i - 1][j], sparseTable[i - 1][j + (1 << (i - 1))]);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int pa = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
		int pb = upper_bound(primes.begin(), primes.end(), b) - primes.begin() - 1;
		if (pa == primes.size() || pb < 0 || pb < pa || (pb - pa + 1 < 3)) {
			cout << "-1\n";
		} else {
		    pa += 2;
			int d = pb - pa + 1;
			int ans = min(sparseTable[lg[d]][pa], sparseTable[lg[d]][pb - (1 << lg[d]) + 1]);
			cout << ans << "\n";
		}
	}
}
