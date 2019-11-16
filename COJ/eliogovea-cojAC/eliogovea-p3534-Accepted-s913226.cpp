#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int cnt[N + 5];
int p[N + 5];

int sum[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		p[i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		if (!cnt[i]) {
			for (int j = i; j <= N; j += i) {
				cnt[j]++;
				p[j] *= i;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		sum[i] = sum[i - 1];
		if (cnt[i] == 3 && p[i] == i) {
			sum[i]++;
		}
	}
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
}
