#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int V = 40;

	vector <long long> c(V); // catalan
	c[0] = 1;
	c[1] = 1;
	for (int i = 2; i < V; i++) {
		for (int j = 0; j < i; j++) {
			c[i] += c[j] * c[i - j];
		}
	}

	vector <vector <long long> > comb(V, vector <long long> (V));
	for (int i = 0; i < V; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

	const int N = 100 * 1000;
	vector <bool> sieve(N);
	for (int i = 2; i * i < N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j < N; j += i) {
				sieve[j] = true;
			}
		}
	}
	vector <int> primes;
	for (int i = 2; i < N; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int te = 0;
		long long cc = 1;
		for (int i = 0; primes[i] * primes[i] <= n; i++) {
			if (n % primes[i] == 0) {
				int e = 0;
				while (n % primes[i] == 0) {
					e++;
					n /= primes[i];
				}
				cc *= comb[te + e][e];
				te += e;
			}
		}
		if (n > 1) {
			cc *= (long long)(te + 1); //comb[te + 1][1];
			te++;
		}
		long long ans = cc * c[te];
		cout << ans << "\n";
	}
}
