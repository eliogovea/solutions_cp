#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 105;

int tc, n, dp[MAXN], ac[MAXN];
pair<int, int> cl[MAXN];

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cl[i].second >> cl[i].first;
			ac[i] = ac[i - 1] + cl[i].second;
		}
		sort(cl + 1, cl + n + 1);
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + (cl[i].second + 10) * cl[i].first;
			for (int j = i - 1; j; j--) {
				int tmp = dp[j - 1] + (ac[i] - ac[j - 1] + 10) * cl[i].first;
				if (dp[i] > tmp) dp[i] = tmp;
			}
		}
		cout << dp[n] << '\n';
	}
}
