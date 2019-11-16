#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000000;

bool criba[N + 5];

vector<int> p;

inline LL phi(LL n) {
	LL res = n;
	for (int i = 0; i < p.size() && (long long)p[i] * p[i] <= n; i++) {
		if (n % p[i] == 0) {
			res -= res / p[i];
			while (n % p[i] == 0) {
				n /= p[i];
			}
		}
	}
	if (n > 1) {
		res -= res / n;
	}
	return res;
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
	p.push_back(2);
	for (int i = 3; i <= N; i += 2) {
		if (!criba[i]) {
			p.push_back(i);
		}
	}
	LL n;
	while (cin >> n && n) {
        if (n == 1) {
            cout << "2\n";
            continue;
        }
		cout << phi(n) << "\n";
	}
}
