#include <bits/stdc++.h>

using namespace std;

int cnt(int n, int x) {
	int res = 0;
	while (n % x == 0) {
		res++;
		n /= x;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	int ans = 0;
	int cnt5a = cnt(a, 5);
	int cnt5b = cnt(b, 5);
	while (cnt5a != cnt5b) {
		if (cnt5a > cnt5b) {
			a = (a / 5);
			ans++;
			cnt5a--;
		} else {
			b = (b / 5);
			ans++;
			cnt5b--;
		}
	}
	int cnt3a = cnt(a, 3);
	int cnt3b = cnt(b, 3);
	while (cnt3a != cnt3b) {
		if (cnt3a > cnt3b) {
			a = (a / 3);
			ans++;
			cnt3a--;
		} else {
			b = (b / 3);
			ans++;
			cnt3b--;
		}
	}
	int cnt2a = cnt(a, 2);
	int cnt2b = cnt(b, 2);
	while (cnt2a != cnt2b) {
		if (cnt2a > cnt2b) {
			a = a / 2;
			ans++;
			cnt2a--;
		} else {
			b = b / 2;
			ans++;
			cnt2b--;
		}
	}
	if (a != b) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}
