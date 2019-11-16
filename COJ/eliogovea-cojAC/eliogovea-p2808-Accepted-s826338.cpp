#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 500005;

int t;

const ull B = 31;

string s;
ull HASH[N], POW[N];

ull get(int s, int e) {
	return HASH[e] - HASH[s] * POW[e - s];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	POW[0] = 1;
	for (int i = 1; i < N; i++) {
		POW[i] = POW[i - 1] * B;
	}
	while (t--) {
		cin >> s;
		int n = s.size();
		for (int i = 1; i <= n; i++) {
			HASH[i] = HASH[i - 1] * B + s[i - 1] - 'a';
		}
		ull x = HASH[n];
		int ans = n;
		for (int i = 1; i + i <= n; i++) {
			if (n % i) {
				continue;
			}
			ull val = 0;
			for (int j = 1; j <= n / i; j++) {
				val = val * POW[i] + HASH[i];
			}
			if (val == x) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
}
