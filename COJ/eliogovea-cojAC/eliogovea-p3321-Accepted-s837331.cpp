#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 10000000000LL;

const int N = 1000000;

bool criba[N + 5];
LL P[N + 5];

void print(int n) {
	if (n < 31) {
		cout << P[n] << "\n";
		return;
	}
	string str;
	LL v = P[n];
	while (v) {
		str += '0' + (v % 10LL);
		v /= 10LL;
	}
	while (str.size() < 10) {
		str += '0';
	}
	reverse(str.begin(), str.end());
	cout << str << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N; j += i) {
				criba[j] = true;
			}
		}
	}
	P[1] = 1;
	P[2] = 2;
	for (LL i = 3; i <= N; i++) {
		P[i] = P[i - 1];
		if (!criba[i]) {
			P[i] *= i;
			P[i] %= MOD;
		}
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		print(n);
	}
}
