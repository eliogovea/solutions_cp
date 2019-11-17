#include <bits/stdc++.h>

using namespace std;

const int N = 5000000;

bool ans[N + 5];

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i < N; i += 2) {
		for (int j = 1; i * i + j * j <= N; j += 2) {
			ans[i * i + j * j] = true;
		}
	}
	for (int i = 1; i <= N; i += 2) {
		if (ans[i]) {
			for (int j = i + i; j <= N; j += i) {
				ans[j] = true;
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (ans[n] ? "YES" : "NO") << "\n";
	}
}

