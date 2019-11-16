#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 100005;

const ull C = 3421;
const ull B = 31;

int n;
string a, b;

ull ha[N], hb[N];
ull POW[N];

pair<ull, int> v[N], pp;

inline ull get(ull *h, int s, int e) {
	return h[e] - h[s] * POW[e - s];
}

bool compare(int ba, int bb, int len) {
	int lo = 0, hi = len;
	int x = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (get(ha, ba, ba + mid) == get(hb, bb, bb + mid)) {
			x = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return b[bb + x] < a[ba + x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> a >> b;
	ha[0] = hb[0] = C;
	POW[0] = 1;
	for (int i = 1; i <= n; i++) {
		ha[i] = ha[i - 1] * B + a[i - 1] - 'A';
		hb[i] = hb[i - 1] * B + b[i - 1] - 'A';
		POW[i] = POW[i - 1] * B;
	}
	int lo = 0, hi = n;
	ull ans_len = 0;
	ull ans_beg = 0;
	ull ans_hash;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool ok = false;
		int cnt = 0;
		for (int i = 0; i + mid <= n; i++) {
			v[cnt].first = get(ha, i, i + mid);
			v[cnt].second = i;
			cnt++;
		}
		sort(v, v + cnt);
		for (int i = 0; i + mid <= n; i++) {
			ull tmp = get(hb, i, i + mid);
			pp = *lower_bound(v, v + cnt, make_pair(tmp, -1));
			if (tmp == pp.first) {
				ok = true;
				if (mid > ans_len || (mid == ans_len && tmp != ans_hash && compare(ans_beg, i, mid))) {
					ans_len = mid;
					ans_beg = pp.second;
					ans_hash = tmp;
				}
			}
		}
		if (ok) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	for (int i = 0; i < ans_len; i++) {
		cout << a[ans_beg + i];
	}
	cout << "\n";
}
