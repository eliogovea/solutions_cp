#include <bits/stdc++.h>

using namespace std;

const int N = 10000000;

int ans[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		ans[i] = 3;
	}
	for (int i = 1; i * (i + 1) / 2 <= N; i++) {
		for (int j = i; j * (j + 1) / 2 <= N - i * (i + 1) / 2; j++) {
			ans[i * (i + 1) / 2 + j * (j + 1) / 2] = 2;
		}
	}
	for (int i = 1; i * (i + 1) / 2 <= N; i++) {
		ans[i * (i + 1) / 2] = 1;
	}
	int n;
	while (cin >> n) {
		cout << ans[n] << "\n";
	}
}
