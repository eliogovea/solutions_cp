#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (LL)a * b % MOD;
}

const int N = 1000000;

int sum[N + 5];

int t;
LL a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		sum[i] = mul(i, mul(i, i));
		add(sum[i], sum[i - 1]);
	}
	cin >> t;
	while (t--) {
		cin >> a >> b;
		{
			LL lo = 0;
			LL hi = N;
			LL res = 0;
			while (lo <= hi) {
				LL mid = (lo + hi) / 2LL;
				if (mid * mid * mid < a) {
					res = mid;
					lo = mid + 1LL;
				} else {
					hi = mid - 1LL;
				}
			}
			a = res;
		}
		{
			LL lo = 0;
			LL hi = N;
			LL res = 0;
			while (lo <= hi) {
				LL mid = (lo + hi) / 2LL;
				if (mid * mid * mid <= b) {
					res = mid;
					lo = mid + 1LL;
				} else {
					hi = mid - 1LL;
				}
			}
			b = res;
		}
		int ans = sum[b];
		add(ans, MOD - sum[a]);
		//cerr << a << " " << " " << b << "\n";
		cout << ans << "\n";
	}
}
