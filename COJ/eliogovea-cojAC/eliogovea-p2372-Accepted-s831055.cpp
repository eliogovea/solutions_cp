#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int BASE = 31;

const int N = 200005;

int n;
string s;

ull POW[N];
ull HASH[N];

inline ull val(char ch) {
	return ch - 'a' + 1;
}

ull v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	POW[0] = 1;
	for (int i = 1; i <= n; i++) {
		POW[i] = POW[i - 1] * BASE;
		HASH[i] = HASH[i - 1] * BASE + val(s[i - 1]);
	}
	int lo = 0;
	int hi = n;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int cnt = 0;
		for (int i = 0; i + mid <= n; i++) {
			v[cnt++] = HASH[i + mid] - HASH[i] * POW[mid];
		}
		sort(v, v + cnt);
		bool ok = false;
		for (int i = 1; i < cnt; i++) {
			if (v[i] == v[i - 1]) {
				ok = true;
				break;
			}
		}
		if (ok) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
}
