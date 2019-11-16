#include <bits/stdc++.h>

using namespace std;

typedef vector <int> bint;
const int BASE = 10;
const bint ZERO(1, 0);
const bint ONE(1, 1);

bint add(const bint &a, const bint &b) {
	int sz = max(a.size(), b.size());
	bint res(sz);
	int carry = 0;
	for (int i = 0; i < sz; i++) {
		if (i < a.size()) {
			carry += a[i];
		}
		if (i < b.size()) {
			carry += b[i];
		}
		res[i] = carry % BASE;
		carry /= BASE;
	}
	if (carry > 0) {
		res.push_back(carry);
	}
	return res;
}

bint mul(const bint &a, int k) {
	bint res(a.size());
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		carry += a[i] * k;
		res[i] = carry % BASE;
		carry /= BASE;
	}
	while (carry > 0) {
		res.push_back(carry % BASE);
		carry /= BASE;
	}
	return res;
}

bint mul(const bint &a, const bint &b) {
	bint res(a.size() + b.size() - 1);

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			res[i + j] += a[i] * b[j];
		}
	}
	int carry = 0;
	for (int i = 0; i < res.size(); i++) {
		carry += res[i];
		res[i] = carry % BASE;
		carry /= BASE;
	}
	while (carry > 0) {
		res.push_back(carry % BASE);
		carry /= BASE;
	}
	return res;
}

void print(const bint &x) {
	for (int i = ((int)x.size()) - 1; i >= 0; i--) {
		cout << x[i];
	}
}

const int N = 100;
bint p2[N + 5], p5[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	p2[0] = ONE;
	p5[0] = ONE;

	for (int i = 1; i <= N; i++) {
		p2[i] = mul(p2[i - 1], 2);
		p5[i] = mul(p5[i - 1], 5);
	}

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int x = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				x = i;
				break;
			}
		}
		if (x == -1) {
			bint ans = ZERO;
			for (int i = 0; i < s.size(); i++) {
				ans = mul(ans, 2);
				if (s[i] == '1') {
					ans = add(ans, ONE);
				}
			}
			print(ans);
			cout << "\n";
		} else {
			bint a = ZERO;
			for (int i = 0; i < x; i++) {
				a = mul(a, 2);
				if (s[i] == '1') {
					a = add(a, ONE);
				}
			}

			int k = s.size() - x - 1;
			bint b = ZERO;
			for (int i = x + 1; i < s.size(); i++) {
                b = mul(b, 2);
				if (s[i] == '1') {
					b = add(b, ONE);
				}
			}

			b = mul(b, p5[k]);

			if (b.size() < k) {
				int c = k - b.size();
				for (int i = 0; i < c; i++) {
					b.push_back(0);
				}
			}
			print(a);
			cout << ".";
			print(b);
			cout << "\n";
		}
	}

}
