#include <bits/stdc++.h>

using namespace std;

int ans[100];

const int N = 100000;

int cnt[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 64; i++) ans[i] = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			cnt[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (ans[cnt[i]] == -1) {
			ans[cnt[i]] = i;
		}
	}
	for (int i = 63; i > 0; i--) {
        if (ans[i] == -1 || ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << ans[n] << "\n";
	}
}
