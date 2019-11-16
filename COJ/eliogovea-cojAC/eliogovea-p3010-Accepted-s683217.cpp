#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const LL inf = 1000000000LL;

LL tc, a, b, lo, hi, ans;
vector<LL> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (LL i = 0; i <= inf; i = 2LL * (i + 1LL) - 1LL) v.push_back(i);
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		ans = 0LL;
		for (int i = 0; v[i] <= a + b; i++)
			ans += min(v[i], a) - max(0LL, v[i] - b) + 1LL;
		cout << ans << "\n";
	}
}
