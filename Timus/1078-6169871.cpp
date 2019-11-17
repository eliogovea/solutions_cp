// Problem: pace=1&num=1078
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 505;

struct seg {
	int b, e, id;
	seg() {}
	seg(int x, int y, int z) : b(x), e(y), id(z) {}
	const int len() const {
		return e - b;
	}
} a[N];

bool operator < (const seg &a, const seg &b) {
	if (a.len() != b.len()) {
		return a.len() < b.len();
	}
	if (a.b != b.b) {
		return a.b < b.b;
	}
	if (a.e != b.e) {
		return a.e < b.e;
	}
	return a.id < b.id;
}

int n;
int dp[N], ans;
int rec[N];
vector<int> v;

int main() {
	//freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].b >> a[i].e;
		a[i].id = i + 1;
	}
	sort(a, a + n);
	ans = -1;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		rec[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j].b > a[i].b && a[j].e < a[i].e && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				rec[i] = j;
			}
		}
		if (ans == -1 || dp[i] > dp[ans]) {
			ans = i;
		}
	}
	cout << dp[ans] << "\n";
	int cur = ans;
	while (true) {
		v.push_back(a[cur].id);
		if (rec[cur] == -1) {
			break;
		}
		cur = rec[cur];
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
		if (i != 0) {
			cout << " ";
		}
	}
	cout << "\n";
}