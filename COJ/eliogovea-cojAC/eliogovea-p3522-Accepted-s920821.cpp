#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int sum[N + 5];

int n, x;

long long bit[N + 5];

void update(int p, int v) {
	while (p <= 2 * n + 5) {
		bit[p] += v;
		p += p & -p;
	}
}

long long query(int p) {
	long long res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			sum[j] += i;
		}
	}
	cin >> n;
	int a = 0;
	int d = 0;
	long long ans = 0;
	update(n + 1, 1);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (sum[x] > x) {
			a++;
		} else if (sum[x] < x){
			d++;
		}
		int diff = n + 1 + a - d;
		ans += query(diff);
		update(diff, 1);
	}
	cout << ans << "\n";
}
