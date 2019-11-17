// Problem: pace=1&num=1846
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
char tipo[N];
int a[N], c[N];
vector<int> b;
int cnt[N];

int T[4 * N];

int gcd(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		T[x] = v;
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, p, v);
		update(2 * x + 1, m + 1, r, p, v);
		T[x] = gcd(T[2 * x], T[2 * x + 1]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("data.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tipo[i] >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	int sz = b.size();
	for (int i = 0; i < n; i++) {
		c[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	for (int i = 0; i < n; i++) {
		if (tipo[i] ==  '+') {
			if (cnt[c[i]] == 0) {
				update(1, 1, sz, c[i], a[i]);
			}
			cnt[c[i]]++;
		} else {
			if (cnt[c[i]] == 1) {
				update(1, 1, sz, c[i], 0);
			}
			cnt[c[i]]--;
		}
		if (T[1] == 0) {
			cout << "1\n";
		} else {
			cout << T[1] << "\n";
		}
	}
}