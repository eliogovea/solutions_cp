#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int cnt[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			if (i * i + j * j > 1000000) {
				break;
			}
			int c2 = i * i + j * j;
			double cd = sqrt(c2);
			int c = cd;
			if (c * c == c2) {
				cnt[c]++;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		cnt[i] += cnt[i - 1];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << cnt[n] << "\n";
	}
}
