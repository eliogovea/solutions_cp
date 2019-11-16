#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int tc, n, cnt[1 << 16];
double tot, c[20], dp[1 << 16], pp[20], f[20], ans;


int main() {
	f[0] = 1;
	for (int i = 1; i <= 15; i++)
		f[i] = double(i) * f[i - 1];
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		cin >> n;
		tot = 0;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			tot += c[i];
		}
		for (int i = 1; i <= n + 1; i++) pp[i] = 0.0;
		for (int i = 0; i < (1 << n); i++) {
			dp[i] = 0;
			cnt[i] = 0;
		}
		dp[0] = 1;
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) cnt[i]++;
			for (int j = 0; j < n; j++)
				if (!(i & (1 << j))) {
					dp[i | (1 << j)] += dp[i] * (c[j] / (tot - (double)(cnt[i])));
				}
		}

		for (int i = 0; i < (1 << n); i++) {
			double tmp = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) {
					tmp += (c[j] - 1.0);
				}
			pp[cnt[i] + 1] += dp[i] * (tmp / (tot - double(cnt[i])));
		}
		for (int i = 1; i <= n + 1; i++)
			ans += (double(i)) * pp[i];
		cout.precision(3);
		cout << "Case " << cas << ": " << fixed << ans << "\n";
	}
}
