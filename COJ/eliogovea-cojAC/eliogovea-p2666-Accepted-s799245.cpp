#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int LOGN = 22;
int n, a[N];

short st[LOGN][N];
short LOG[N];
void build() {
	for (int i = 2; i <= n; i++) {
		LOG[i] = LOG[i / 2] + 1;
	}
	for (int i = 1; i <= n; i++) {
		st[0][i] = a[i];
	}
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int query(int x, int y) {
	int l = LOG[y - x + 1];
	return __gcd(st[l][x], st[l][y - (1 << l) + 1]);
}

int len;
vector<pair<int, int> > ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build();
	for (int i = 1; i <= n; i++) {
		int lo = 1, hi = i;
		int ll = 1;
		while (lo <= hi) {
			int m = (lo + hi) >> 1;
			if (query(i - m + 1, i) % a[i] == 0) {
				ll = m;
				lo = m + 1;
			} else {
				hi = m - 1;
			}
		}

		lo = 1;
		hi = n - i + 1;
		int rr = 1;
		while (lo <= hi) {
			int m = (lo + hi) >> 1;
			if (query(i, i + m - 1) % a[i] == 0) {
				rr = m;
				lo = m + 1;
			} else {
				hi = m - 1;
			}
		}
		int l = ll + rr - 1;
		if (l > len) {
			len = l;
			ans.clear();
			ans.push_back(make_pair(i - ll + 1, i + rr - 1));
		} else if (l == len) {
			ans.push_back(make_pair(i - ll + 1, i + rr - 1));
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << len << " " << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}
