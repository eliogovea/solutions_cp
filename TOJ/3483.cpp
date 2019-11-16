//============================================================================
// Name        : test.cpp
// Author      : eliogovea
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 3483.     Common Divisor

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool criba[N];
vector<int> p;

int cnt_div(int n) {
	int res = 1;
	for (int i = 0; p[i] * p[i] <= n; i++) {
		if (n % p[i] == 0) {
			int tmp = 1;
			while (n % p[i] == 0) {
				tmp++;
				n /= p[i];
			}
			res *= tmp;
		}
	}
	if (n > 1) {
		res *= 2;
	}
	return res;
}

int main() {
	for (int i = 2; i * i<= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N; j += i) {
				criba[j] = false;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!criba[i]) {
			p.push_back(i);
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, a, b, g;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		g = __gcd(a, b);
		cout << cnt_div(g) << "\n";
	}
}
