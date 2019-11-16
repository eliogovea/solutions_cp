#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

const int mod = 1000000007;

int t, n;
int f[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	f[0] = f[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << f[n] << "\n";
	}
}