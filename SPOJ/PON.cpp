#include <bits/stdc++.h>
 
using namespace std;
 
namespace NumberTheory {
	using LL = long long;
 
	inline LL mul(LL a, LL b, LL m) {
		// return (__int128)a * b % m;
		// a %= m; b %= m;
		if (m <= 2e9) return a * b % m;
		LL q = (long double)a * b / m;
		LL r = a * b - q * m; r %= m;
		if (r < 0) r += m;
		return r;
	} // to avoid overflow, m < 1e18
 
	inline LL power(LL x, LL n,  LL m) {
		LL y = 1 % n; if (y == 0) return 0;
		x %= m; 
		while (n > 0) {
			if (n & 1) y = mul(y, x, m);
			x = mul(x, x, m);
			n >>= 1;
		}
		return y;
	}
 
	bool ready = false;
	const int P = 1000 * 1000; 
	bool _isPrime[P]; vector <int> primes;
 
	inline bool fastSieve() { // O(n)
		for (int i = 0; i < P; i++) 
			_isPrime[i] = true;
		_isPrime[0] = _isPrime[1] = false;
		primes.reserve(P); //
		for (int i = 2; i < P; i++) {
			if (_isPrime[i]) primes.push_back(i);
			for (int j = 0; j < primes.size() && primes[j] * i < P; j++) {
				_isPrime[primes[j] * i] = false;
				if (i % primes[j] == 0) break;
			}
		}
	}
 
	// Miller Rabin primality test !!!
	inline bool witness(LL x, LL n, LL s, LL d) {
		LL cur = power(x, d, n);
		if (cur == 1) return false;
		for (int r = 0; r < s; r++) {
			if (cur == n - 1) return false;
			cur = mul(cur, cur, n);
		}
		return true;
	}
 
	bool isPrime(long long n) { 
		if (!ready) fastSieve(), ready = true;
		if (n < P) return _isPrime[n];
		if (n < 2) return false;
		for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
			if (n == x) return true;
			if (n % x == 0) return false;
		}
		if (n < 31 * 31) return true;
		int s = 0; LL d = n - 1;
		while (!(d & 1)) s++, d >>= 1;
		// for n int: test = {2, 7, 61}
		// for n < 3e18: test = {2, 3, 5, 7, 11, 13, 17, 19, 23}
		static vector <LL> test = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
		for (long long x : test) {
			if (x % n == 0) return true;
			if (witness(x, n, s, d)) return false;
		}
//		for (auto p : primes) { // slow for testing
//			if ((long long)p * p > n) break;
//			if (n % p == 0) return false;
//		}
		return true;
	} // ends Miller Rabin primality test !!!
}
 
using namespace NumberTheory;
 
void testIsPrime() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << (isPrime(n) ? "YES" : "NO") << "\n";
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	// testMillerRabin();
	// testPollardRho();
	testIsPrime();
}
