#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

const int N = 1500;

int f[N + 5];
long long sum[N + 5];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[1] = 1;
	f[2] = 1;
	sum[1] = 1;
	sum[2] = 2;
	for (int i = 3; i <= N; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
		sum[i] = sum[i - 1] + f[i];
	}
	int t;
	long long a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		a--;
		long long ans = (b / (long long)N) * sum[N] + sum[b % (long long)N] - ((a / (long long)N) * sum[N] + sum[a % (long long)N]);
		cout << ans << "\n";
	}
}
