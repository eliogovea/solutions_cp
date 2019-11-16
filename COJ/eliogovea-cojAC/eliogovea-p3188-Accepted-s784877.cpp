#include <bits/stdc++.h>

using namespace std;

int n;
string s;

typedef unsigned long long ull;

const ull B = 31;

const int N = 40005;

ull hash[N];
ull POW[N];

pair<ull, int> v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	POW[0] = 1;
	for (int i = 1; i < N; i++) {
		POW[i] = POW[i - 1] * B;
	}
	while (cin >> n && n) {
		cin >> s;
		int sz = s.size();
		for (int i = 1; i <= sz; i++) {
			hash[i] = hash[i - 1] * B + s[i - 1] - 'a' + 1;
		}
		int lo = 1;
		int hi = sz - n + 1;
		int ans_len = 0;
		int ans_pos = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			for (int i = 0; i + mid <= sz; i++) {
				v[i].first = hash[i + mid] - hash[i] * POW[mid];
				v[i].second = i;
			}
			sort(v, v + (sz + 1 - mid));
			bool ok = false;
			int last = 0;
			for (int i = 0; i + mid <= sz; i++) {
				if (v[i].first != v[last].first) {
					last = i;
				}
				if (i - last + 1 >= n) {
					ok = true;
					if (ans_len < mid || (ans_len == mid && v[i].second > ans_pos)) {
						ans_len = mid;
						ans_pos = v[i].second;
					}
				}
			}
			if (ok) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (ans_len == 0) {
			cout << "none\n";
		} else {
			cout << ans_len << " " << ans_pos << "\n";
		}
	}
}
