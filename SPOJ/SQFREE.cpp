#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 10 * 1000 * 1000;
 
bool sieve[N + 10];
int mu[N + 10];
int sqfree[N + 10], cnt = 0;
 
int t;
long long n;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	for (int i = 1; i <= N; i++) {
		mu[i] = 1;
	}
 
	for (int i = 2; i <= N; i++) {
		if (!sieve[i]) {
			if ((long long)i * i <= N) {
				for (int j = i * i; j <= N; j += i * i) {
					mu[j] = 0;
				}
			}
			for (int j = i; j <= N; j += i) {
				mu[j] = -mu[j];
				sieve[j] = true;
			}
		}
	}
 
	for (int i = 1; i <= N; i++) {
		if (mu[i] != 0) {
			sqfree[cnt++] = i;
		}
	}
 
	cin >> t;
	while (t--) {
		cin >> n;
 
		long long ans = 0;
		for (int i = 0; i < cnt; i++) {
			if ((long long)sqfree[i] * sqfree[i] > n) {
				break;
			}
			ans += (long long)mu[sqfree[i]] * (n / sqfree[i] / sqfree[i]);
		}
 
		cout << ans << "\n";
	}
 
 
}
