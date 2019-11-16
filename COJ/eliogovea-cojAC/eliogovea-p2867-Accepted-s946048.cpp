#include <bits/stdc++.h>

using namespace std;

const int MOD = 123457;
const int N = 1000000;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int INV2 = power(2, MOD - 2);

bool sieve[N + 5];

int phi[N + 5];
int f[N + 5];
int g[N + 5];
int sumg[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i * i <= N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		phi[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (!sieve[i]) {
			for (int j = i; j <= N; j += i) {
				phi[j] = phi[j] - phi[j] / i;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = mul(i, mul(phi[i], INV2));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			add(g[j], f[i]);
		}
	}
	for (int i = 1; i <= N; i++) {
		g[i] = mul(g[i], i);
	}
	for (int i = 1; i <= N; i++) {
		sumg[i] = sumg[i - 1];
		add(sumg[i], g[i]);
	}
	int n;
	while (cin >> n) {
		cout << sumg[n] << "\n";
	}
}
