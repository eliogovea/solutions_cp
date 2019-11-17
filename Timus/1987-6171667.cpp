// Problem: pace=1&num=1987
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, a[N], b[N], q, x, ans[N];

struct event {
	int x, id, tip;
};

bool operator < (const event &a, const event &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	if (a.tip != b.tip) {
		return a.tip < b.tip;
	}
	return a.id < b.id;
}
vector<event> E;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("data.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		event e;
		e.x = a[i];
		e.tip = -1;
		e.id = i;
		E.push_back(e);
		e.x = b[i];
		e.tip = 1;
		e.id = i;
		E.push_back(e);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> x;
		event e;
		e.x = x;
		e.tip = 0;
		e.id = i;
		E.push_back(e);
		ans[i] = -1;
	}
	sort(E.begin(), E.end());
	vector<int> last;
	for (int i = 0; i < E.size(); i++) {
		if (E[i].tip == -1) {
			last.push_back(E[i].id);
		} else if (E[i].tip == 0) {
			if (last.size() >= 1) {
				ans[E[i].id] = last.back();
			}
		} else {
			if (last.size() >= 1) {
				last.pop_back();
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
}
