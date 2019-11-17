// Problem: pace=1&num=1402
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

typedef vector <int> BigInt;

const BigInt ZERO(1, 0);
const BigInt ONE(1, 1);

BigInt add(BigInt &a, BigInt &b) {
	BigInt res(max(a.size(), b.size()), 0);
	int carry = 0;
	for (int i = 0; i < res.size(); i++) {
		if (i < a.size()) {
			carry += a[i];
		}
		if (i < b.size()) {
			carry += b[i];
		}
		res[i] = carry % 10;
		carry /= 10;
	}
	if (carry) {
		res.push_back(carry);
	}
	return res;
}

BigInt mul(BigInt &a, int v) {
	BigInt res(a.size(), 0);
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		carry += v * a[i];
		res[i] = carry % 10;
		carry /= 10;
	}
	while (carry) {
		res.push_back(carry % 10);
		carry /= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ULL n;
	cin >> n;
	if (n == 1ULL) {
		cout << "0\n";
		return 0;
	}
	BigInt ans = ONE;
	ans = mul(ans, n);
	ans = mul(ans, n - 1);
	BigInt cur = ans;
	for (ULL p = n - 2; p >= 1; p--) {
		cur = mul(cur, p);
		ans = add(ans, cur);
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << "\n";
}
