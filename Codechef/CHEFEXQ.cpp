#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;
const int SQRTN = 400;

int n, q;
int a[N], sa[N];
int lazy[SQRTN];
vector <int> cv[SQRTN];
vector <int> cnt[SQRTN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sa[i] = a[i];
		if (i != 0) {
			sa[i] ^= sa[i - 1];
		}
	}

	int sqrtn = 1 + sqrt(n);

	for (int i = 0; i < n; i += sqrtn) {
		int id =  i / sqrtn;
		int j = min(n, i + sqrtn);
		cv[id].resize(j - i);
		int p = 0;
		for (int x = i; x < j; x++) {
			cv[id][p] = sa[x];
			p++;
		}
		sort(cv[id].begin(), cv[id].end());
	}
	while (q--) {
		int type;
		cin >> type;

		if (type == 1) {
			 // update
			int p, x;
			cin >> p >> x;
			p--;

			int lazy_val = a[p] ^ x;
			a[p] = x;

			if ((p % sqrtn) != 0) {
				while (p < n && (p % sqrtn) != 0) {
					sa[p] ^= lazy_val;
					p++;
				}

				int id = (p - 1) / sqrtn;
				int l = id * sqrtn;
				int r = p;
				
				// push lazy
				if (lazy[id]) {
					for (int i = l; i < r; i++) {
						sa[i] ^= lazy[id];
					}
					lazy[id] = 0;
				}
				
				// rebuild
				int pos = 0;
				for (int i = l; i < r; i++) {
					cv[id][pos] = sa[i];
					pos++;
				}
				sort(cv[id].begin(), cv[id].end());
			}
			
			// lazy update
			while (p < n) {
				lazy[p / sqrtn] ^= lazy_val;
				p += sqrtn;
			}

		} else {
			// query
			int p, k;
			cin >> p >> k;
			p--;
			int ans = 0;
			while (p >= 0 && (p % sqrtn) != sqrtn - 1) {
				if (sa[p] == (k ^ lazy[p / sqrtn])) {
					ans++;
				}
				p--;
			}
			while (p >= 0) {
				int id = p / sqrtn;
				int x = k ^ lazy[id];
				ans += upper_bound(cv[id].begin(), cv[id].end(), x) - lower_bound(cv[id].begin(), cv[id].end(), x);
				p -= sqrtn;
			}
			cout << ans << "\n";
		}
	}
}

