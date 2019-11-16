#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

int k;
double a[MAXN];

string solve() {
	sort(a, a + k);
	double ac = a[0];
	for (int i = 1; i < k; i++) {
		if (ac >= a[i]) return "YES";
		ac += a[i];
	}
	return "NO";
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> k && k) {
		for (int i = 0; i < k; i++) cin >> a[i];
		cout << solve() << '\n';
	}
}
