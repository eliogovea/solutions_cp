#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long x[100005], y[100005], ac[100005], ans = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (i > 0) {
			ac[i] = ac[i - 1];
			ac[i] += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
		}
	}
	for (int i = 1; i < n - 1; i++) {
		long long tmp = ac[i - 1] + ac[n - 1] - ac[i + 1] + abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
		if (ans == -1 || tmp < ans) {
			ans = tmp;
		}
	}
	cout << ans << "\n";
}
