#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int t, n;
int sum[N + 5];

int main() {
  ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			sum[j] += i;
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << sum[n] << "\n";
	}
}
