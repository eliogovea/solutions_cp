#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b, ans;
vector<long long> f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> a >> b;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			f.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		f.push_back(n);
	}
	int sz = f.size();
	for (int i = 1; i < (1 << sz); i++) {
		long long cur = 1;
		bool par = 1;
		for (int j = 0; j < sz; j++) {
			if (i & (1 << j)) {
				cur *= f[j];
				par ^= 1;
			}
		}
		long long tmp = b / cur - (a - 1) / cur;
		if (par) {
			ans -= tmp;
		} else {
			ans += tmp;
		}
	}
	ans = b - a + 1LL - ans;
	cout << ans << "\n";
}
