#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, k, p;
int a[N + 5];
int f[N + 5];
int fact[N + 5];
int ifact[N + 5];

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % p;
		}
		x = (x * x) % p;
		n >>= 1;
	}
	return res;
}

vector <int> primes;
bool sieve[N + 5];
int mu[N + 5];

inline int comb(int a, int b) {
	if (a < b) {
		return 0;
	}
	return (fact[a] * ((ifact[b] * ifact[a - b]) % p)) % p;
}

inline int lucas(int a, int b) {
	if (a < b) {
		return 0;
	}
	int res = 1;
	while ((a | b) && (res > 0)) {
		res = (res * comb(a % p, b % p)) % p;
		a /= p;
		b /= p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);

	sieve[0] = true;
	sieve[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = true;
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
		}
	}
	for (int i = 0; i <= N; i++) {
		mu[i] = 1;
	}
	for (int i = 0; i < primes.size(); i++) {
		int x = primes[i] * primes[i];
		for (int j = x; j <= N; j += x) {
			mu[j] = 0;
		}
	}
	for (int i = 0; i < primes.size(); i++) {
		int x = primes[i];
		for (int j = x; j <= N; j += x) {
			mu[j] = -mu[j];
		}
	}

	while (cin >> n >> k >> p) {
		p = primes[p];
		for (int i = 0; i <= N; i++) {
			f[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			f[a[i]]++;
		}
		fact[0] = 1;
		ifact[0] = 1;
		for (int i = 1; i < p; i++) {
			fact[i] = (fact[i - 1] * i) % p;
			ifact[i] = power(fact[i], p - 2);
		}
		int ans = lucas(n, k);
		cerr << ans << "\n";
		for (int i = 2; i <= N; i++) {
			if (mu[i] == 0) {
				continue;
			}
			int t = 0;
			for (int j = i; j <= N; j += i) {
				t += f[j];
			}
			if (t == 0) {
				continue;
			}
			if (mu[i] == 1) {
				ans = (ans + lucas(t, k)) % p;
			} else {
				ans = (ans + (p - lucas(t, k))) % p;
			}
		}
		cout << ans << "\n";
	}
}
