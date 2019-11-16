#include <bits/stdc++.h>

using namespace std;

typedef vector <int> bigNum;

const bigNum ONE = bigNum(1, 1);

bigNum multiply(const bigNum &x, int k) {
	bigNum result;
	int carry = 0;
	for (int i = 0; i < x.size(); i++) {
		carry += x[i] * k;
		result.push_back(carry % 10);
		carry /= 10;
	}
	while (carry > 0) {
		result.push_back(carry % 10);
		carry /= 10;
	}
	return result;
}

void print(const bigNum &x) {
	for (int i = x.size() - 1; i >= 0; i--) {
		cout << x[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 40;
	vector <bigNum> factorial(N + 1);
	factorial[0] = ONE;
	for (int i = 1; i <= N; i++) {
		factorial[i] = multiply(factorial[i - 1], i);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		print(factorial[n]);
		cout << "\n";
	}
}
