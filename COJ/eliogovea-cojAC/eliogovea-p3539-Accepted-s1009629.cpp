#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long w;
	cin >> n >> w;
	vector <int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	long long lo = 0;
	long long hi = 1000000000000LL;
	long long ans = lo;
	while (lo <= hi) {
		long long mid = (lo + hi) >> 1LL;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (h[i] >= mid) {
				sum += h[i] - mid;
			}
		}
		if (sum >= w) {
			ans = mid;
			lo = mid + 1LL;
		} else {
			hi = mid - 1LL;
		}
	}
	cout << ans << "\n";
}
