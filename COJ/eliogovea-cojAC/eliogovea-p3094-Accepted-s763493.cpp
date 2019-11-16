#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000;

long long n, m, a[N + 5], b[N + 5], cnt[N + 5], used[N + 5], cdiv[N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		cnt[b[i]]++;
	}
	for (int i = 0; i < m; i++) {
		if (used[b[i]]) {
			continue;
		}
		used[b[i]] = true;
		for (int j = b[i] + b[i]; j <= N; j += b[i]) {
			cdiv[j] += cnt[b[i]];
		}
	}
	long long x = 0;
	for (int i = 0; i < n; i++) {
		x += cdiv[a[i]];
	}
	long long y = n * m;
	long long g = __gcd(x, y);
	x /= g;
	y /= g;
	cout << x << "/" << y << "\n";

}
