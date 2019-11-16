#include <bits/stdc++.h>

using namespace std;

struct data {
	int c, a, t;
	int len() {
		return c + a + t;
	}
	const char ch(int p) {
		if (p < c) return 'C';
		if (p < c + a) return 'A';
		return 'T';
	}
	void print() {
		int l = len();
		for (int i = 0; i < l; i++) {
			cout << ch(i);
		}
		cout << "\n";
	}
};

bool operator < (data a, data b) {
	if (a.len() != b.len()) return a.len() < b.len();
	int l = a.len();
	for (int i = 0; i < l; i++) {
		if (a.ch(i) != b.ch(i)) return a.ch(i) < b.ch(i);
	}
	return false;
}

int t, n;

int val[5];

vector <data> ans;

void dfs(int n, int d) {
	if (d == 2) {
		val[d] = n;
		ans.push_back((data) {val[0], val[1], val[2]});
	} else {
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				val[d] = i;
				dfs(n / i, d + 1);
				if (i * i != n) {
					val[d] = n / i;
					dfs(i, d + 1);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans.clear();
		cin >> n;
		dfs(n, 0);
		sort(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) {
			ans[i].print();
		}
	}
}
