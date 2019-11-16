#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int N = 10000;
	const int INF = 500 * 1000;
	vector <int> cnt(INF);
	vector <int> u(N);
	u[0] = 1;
	u[1] = 2;
	cnt[3] = 1;
	int pos = 3;
	for (int i = 2; i < N; i++) {
		while (cnt[pos] != 1) {
			pos++;
		}
		u[i] = pos++;
		for (int j = 0; j < i; j++) {
			cnt[u[i] + u[j]]++;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << u[n - 1] << "\n";
	}
}
