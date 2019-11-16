#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <long long> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long sumB = 0;
	for (int i = 0; i < m; i++) {
		sumB += b[i];
	}
	long long curSum = 0;
	long long ans = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && b[j] <= a[i]) {
			curSum += b[j];
			j++;
		}
		ans += (long long)j * a[i] - curSum;
		ans += (sumB - curSum) -(long long)(m - j) * a[i];
	}
	cout << ans << "\n";
}
