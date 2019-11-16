#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1 << 21;

int sieve[N];
int primes[N], szp;

inline LL mul(LL a, LL b, LL mod) {
  // assert(0 <= a && a < mod);
  // assert(0 <= b && b < mod);
  if (mod < int(1e9)) {
		return a * b % mod;
	}
  LL k = (LL)((long double)a * b / mod);
  LL res = a * b - k * mod;
  res %= mod;
  if (res < 0) {
		res += mod;
	}
  return res;
}

// inline LL mul(LL a, LL b, LL mod) {
	// LL res = 0;
	// a %= mod;
	// while (b) {
		// if (b & 1) {
			// res = res + a;
			// if (res >= mod) {
				// res -= mod;
			// }
		// }
		// a = a + a;
		// if (a >= mod) {
			// a -= mod;
		// }
	// }
	// return res;
// }

inline LL power(LL x, LL n, LL mod) {
	LL res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x, mod);
		}
		x = mul(x, x, mod);
		n >>= 1;
	}
	return res;
}

const int test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, -1};

inline bool isPrime(LL n) {
	if (n < N) {
		return !sieve[n];
	}
	for (int i = 0; test[i] > 0; i++) {
		if (n % test[i] == 0) {
			return false;
		}
	}
	LL d = n - 1;
	int a = 0;
	while (!(d & 1)) {
		d >>= 1;
		a++;
	}
	for (int i = 0; test[i] > 0; i++) {
		LL cur = power(test[i], d, n);
		if (cur == 1) {
			continue;
		}
		bool ok = false;
		for (int j = 0; j < a; j++) {
			if (cur == n - 1) {
				ok = true;
				break;
			}
			cur = mul(cur, cur, n);
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

inline LL isSquare(ULL x) {
	ULL lo = 1;
	ULL hi = (1LL << 32) - 1LL;
	while (lo <= hi) {
		ULL mid = (lo + hi) >> 1ULL;
		if (mid * mid == x) {
			return (LL)mid;
		}
		if (mid * mid > x) {
			hi = mid - 1ULL;
		} else {
			lo = mid + 1ULL;
		}
	}
	return -1;
}

inline LL gcd(LL a, LL b) {
	LL tmp;
	while (b) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

inline LL factor(LL n) {
	static LL a, b;
	a = 1 + rand() % (n - 1);
	b = 1 + rand() % (n - 1);
	#define f(x)	(mul(x, x + b, n) + a)
	LL x = 2, y = 2, d = 1;
	while (d == 1 || d == -1) {
        // cerr << x << " " << y << "\n";
		x = f(x);
		y = f(f(y));
		d = gcd(x - y, n);
	}
	return abs(d);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("dat.txt", "r", stdin);

	sieve[0] = sieve[1] = -1;
	for (int i = 2; i * i < N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j < N; j += i) {
				if (!sieve[j]) {
					sieve[j] = i;
				}
			}
		}
	}

	szp = 0;
	for (int i = 2; i < N; i++) {
		if (!sieve[i] || sieve[i] == i) {
			sieve[i] = i;
			primes[szp++] = i;
		}
	}

	int t;
	LL n;
	cin >> t;
	while (t--) {
		cin >> n;

		if (n < N) {
			while (n != 1) {
				cout << sieve[n];
				n /= sieve[n];
				if (n != 1) {
					cout << " ";
				}
			}
			cout << "\n";
		} else {
		    for (int i = 0; i < szp && (LL)primes[i] * primes[i] <= n; i++) {
				while (n % primes[i] == 0) {
					cout << primes[i];
					n /= primes[i];
					if (n != 1) {
						cout << " ";
					}
				}
			}
			if (n != 1) {
				if (n < N) { // assert(false);
					cout << n;
				} else {
					if (isPrime(n)) {
						cout << n;
					} else {
						LL v = isSquare(n);
						if (v != -1) {
							cout << v << " " << v;
						} else {
							LL x = factor(n);
							LL y = n / x;
							if (x > y) {
								swap(x, y);
							}
							cout << x << " " << y;
						}
					}
				}
			}
			cout << "\n";
		}
	}
}
