#include <iostream>
#include <cmath>

using namespace std;

int tc, n, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
    cin >> n;
		ans = 1 + (int)(log10(2.0 * M_PI * sqrt(2.0)) + (1.0 + n) * log10(1.5));
		cout << "Case " << i << ": " << ans << "\n";
	}
}
