// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150A

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 10000;
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
	for (int i = 2; i <= N; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
		}
	}
	int n;
	while (cin >> n && n) {
		long long sum = 0;
		int ans = 0;
		for (int i = 0, j = 0; i < primes.size(); i++) {
			sum += primes[i];
			while (j < i && sum > n) {
				sum -= primes[j];
				j++;
			}
			if (sum == n) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}
