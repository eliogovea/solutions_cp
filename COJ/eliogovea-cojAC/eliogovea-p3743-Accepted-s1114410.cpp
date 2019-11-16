#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;
const int MOD = 1000000007;

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

int fact[N + 5];
int invFact[N + 5];
int sum[N + 5];

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	invFact[0] = 1;
	sum[0] = invFact[0];
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		invFact[i] = power(fact[i], MOD - 2);
		sum[i] = sum[i - 1];
		add(sum[i], invFact[i]);
	}
	while (cin >> n) {
		cout << mul(fact[n - 2], sum[n - 2]) << "\n";
	}
}
