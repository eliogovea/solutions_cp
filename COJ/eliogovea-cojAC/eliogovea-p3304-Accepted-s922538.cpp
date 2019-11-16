#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL M = 1000000007;

inline LL mul(LL a, LL b, LL MOD) {
	return a * b % MOD;
}

const int N = 1000005;

LL f1[N], f2[N], f3[N];

inline LL power(LL x, LL n, const LL MOD) {
	LL res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x, MOD);
		}
		x = mul(x, x, MOD);
		n >>= 1;
	}
	return res;
}

const LL M1 = (M - 1) / 2;
const LL M2 = 2;
const LL M1i = power(M2, M1 - 2, M1);
const LL M2i = 1;

LL solve(LL a, LL b, LL c) {
	LL v1 = power(f2[b], f3[c], M1);
	LL v2 = 1LL;
	if (b > 1LL) {
		v2 = 0LL;
	}
    LL e1 = mul(M2, M1i, M - 1LL);
    e1 = mul(e1, v1, M - 1LL);
    LL e2 = mul(M1, M2i, M - 1LL);
    e2 = mul(e2, v2, M - 1);
    LL e = (e1 + e2) % (M - 1LL);
	return power(f1[a], e1 + e2, M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	f1[0] = 1;
	f2[0] = 1;
	f3[0] = 1;
	for (int i = 1; i < N; i++) {
		f1[i] = mul(f1[i - 1], i, M);
		f2[i] = mul(f2[i - 1], i, M1);
		f3[i] = mul(f3[i - 1], i, M1 - 1);
	}
	int t;
	int a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << solve(a, b, c) << "\n";
	}
}
