#include <bits/stdc++.h>

using namespace std;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19};

int t;
string s;
int cnt[300];

inline int get(int n, int x) {
	int res = 0;
	int xx = x;
	while (xx <= n) {
		res += n / xx;
		xx *= x;
	}
	return res;
}

long long power(long long x, int n) {
	long long res = 1;
	while (n) {
		if (n & 1) {
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> s;
		for (int i = 'A'; i <= 'Z'; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i]]++;
		}
		long long ans = 1LL;
		for (int i = 0; i < 8; i++) {
			int pp = p[i];
			int e = get(s.size(), pp);
			for (int j = 'A'; j <= 'Z'; j++) {
				e -= get(cnt[j], pp);
			}
			ans *= power(pp, e);
		}
		cout << "Data set " << cas << ": " << ans << "\n";
	}
}
