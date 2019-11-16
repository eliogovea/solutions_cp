// Problem: pace=1&num=1055
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 50000;

bool criba[N + 5];

int n, m;

int get(int n, int p) {
	int res = 0;
	int cur = p;
	while (true) {
		res += n / cur;
		if (cur > n / p) {
            break;
		}
		cur *= p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			criba[j] = true;
		}
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
        if (criba[i]) {
            continue;
        }
		int tmp = get(n, i) - get(m, i) - get(n - m, i);
		//cout << i << " " << tmp << "\n";
		if (tmp > 0) {
			ans++;
		}
	}
	cout << ans << "\n";
}
