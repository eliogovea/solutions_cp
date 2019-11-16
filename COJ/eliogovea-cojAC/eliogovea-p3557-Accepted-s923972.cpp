#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline LL mul(LL a, LL b, LL mod) {
	a %= mod;
	b %= mod;
	LL res = 0;
	while (b) {
		if (b & 1) {
			res += a;
			if (res >= mod) {
				res -= mod;
			}
		}
		a += a;
		if (a >= mod) {
			a -= mod;
		}
		b >>= 1LL;
	}
	return res;
}

inline LL power(LL x, LL n, LL mod) {
	LL res = 1LL;
	while (n) {
		if (n & 1LL) {
			res = mul(res, x, mod);
		}
		x = mul(x, x, mod);
		n >>= 1LL;
	}
	return res;
}

const int MAX = 110;

bool criba[MAX + 5];

inline bool miller_rabin(LL n) {
    if (!(n & 1LL)) {
        return false;
    }
	LL t = n - 1LL;
	int s = 0;
	while (!(t & 1LL)) {
		t >>= 1LL;
		s++;
	}
	const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, -1};
	for (int i = 0; p[i] > 0; i++) {
		LL cur = power(p[i], t, n);
		if (cur == 1LL) {
			continue;
		}
		bool good = false;
		for (int j = 0; j < s; j++) {
			if (cur == n - 1) {
				good = true;
				break;
			}
			cur = mul(cur, cur, n);
		}
		if (!good) {
			return false;
		}
	}
	return true;
}

inline bool prime(LL n) {
	if (n <= MAX) {
		return !criba[n];
	}
	return miller_rabin(n);
}

int t, n;
LL k, x;

LL get(LL x) {
	if (x <= MAX) {
        x--;
		while (x > 0 && criba[x]) {
			x--;
		}
		return x;
	}
	x--;
	while (!miller_rabin(x)) {
        x--;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	criba[0] = criba[1] = true;
	for (int i = 2; i <= MAX; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				criba[j] = true;
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;

		if (n == 1) {
            cin >> x;
            LL y = get(x);
            LL ans = (x - y) % (k + 1LL);
            if (ans) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
		}

		bool win = false;
		long long sum = 0;
        bool op = false;
		while (n--) {
			cin >> x;
			if (x <= 1LL) {
				continue;
			}
			if (prime(x)) {
                op = true;
			}
			if (x == 2) {
                continue;
			}
			if (win) {
				continue;
			}
			LL p = get(x);
			if (x - p <= k) {
				win = true;
			}
			sum ^= ((x - p) % (k + 1LL));
		}
		if (op) {
            cout << "YES\n";
            continue;
		}
		if (win || sum) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
