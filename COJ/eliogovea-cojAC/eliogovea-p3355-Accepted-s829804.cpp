#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int n;
int criba[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!criba[i]) {
			for (int j = i; j <= n; j += i) {
				criba[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		ans += (criba[i] == 2);
	}
	cout << ans << "\n";
}