#include <iostream>

using namespace std;

int b, g, k;
long long c[35][35], ans;

int main() {
	for (int i = 1; i <= 30; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> b >> g >> k && (b | g | k)) {
		ans = 0;
		for (int i = 0; i <= k; i++) {
			if (i < 4 || k - i < 1 || i > b || k - i > g) {
				continue;
			}
			ans += c[b][i] * c[g][k - i];
		}
		cout << ans << "\n";
	}
}
