#include <iostream>

using namespace std;

long long tc, n, ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = 0;
		for (long long p10 = 10; n / (p10 / 10); p10 *= 10) {
			int c = (n + 1) / p10;
			int r = (n + 1) % p10;
			ans += c * (p10 / 10) * 20;
			int x = r / (p10 / 10);
			for (int i = 2; i < x; i += 2) {
        ans += i * (p10 / 10);
			}
			int y = r % (p10 / 10);
			if (x == 2 || x == 4 || x == 6 || x == 8) {
				ans += x * y;
			}
		}
		cout << ans << "\n";
	}
}
