#include <bits/stdc++.h>

using namespace std;

inline void add(int & a, int b, int m) {
	a += b;
	if (a >= m) {
		a -= m;
	}
}

inline int mul(int a, int b, int m) {
	return (long long)a * b % m;
}

inline int power(int x, int n, int m) {
	int y = 1 % m;
	while (n > 0) {
		if (n & 1) {
			y = mul(y, x, m);
		}
		x = mul(x, x, m);
		n >>= 1;
	}
	return y;
}

int slow(int n, int k, int m) {
	vector <int> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = mul(f[i - 1], k, m);
	}
	for (int i = 1; i <= n; i++) {
		for (int x = i + i; x <= n; x += i) {
			add(f[x], m - f[i], m);
		}
	}
	return f[n];
}

vector <int> getSieve(int n) {
	vector <int> f(n + 1);
	for (int i = 2; i <= n; i++) {
		if (!f[i]) {
			for (int j = i; j <= n; j += i) {
				f[j] = i;
			}
		}
	}
	return f;
}

vector <int> getPrimes(int n, vector <int> & sieve) {
	vector <int> primes;
	while (n > 1) {
		int p = sieve[n];
		primes.push_back(p);
		while (n > 1 && sieve[n] == p) {
			n /= p;
		}
	}
	return primes;
}

int fast(int n, int k, int mod, vector <int> & sieve) {
	auto primes = getPrimes(n, sieve);
	int c = primes.size();
	vector <int> divs(1 << c, 1);
	vector <int> bits(1 << c, 0);
	vector <int> pk(1 << c);
	for (int i = 0; i < c; i++) {
		divs[1 << i] = primes[i];
	}
	for (int m = 1; m < (1 << c); m++) {
		divs[m] = divs[m ^ (m & -m)] * divs[m & -m];
		bits[m] = bits[m ^ (m & -m)] + 1;
	}
	for (int m = 0; m < (1 << c); m++) {
		pk[m] = power(k, n / divs[m], mod);
	}
	int ans = 0;
	for (int m = 0; m < (1 << c); m++) {
		if (bits[m] & 1) { //
			add(ans, mod - pk[m], mod);
		} else {
			add(ans, pk[m], mod);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int N = 2 * 100 * 1000;
	auto sieve = getSieve(N + 1);

	int t;
	cin >> t;

	while (t--) {
		int n, k, m;
		cin >> n >> k >> m;
		int ans = fast(n, k, m, sieve);
		cout << ans << "\n";
	}
}
