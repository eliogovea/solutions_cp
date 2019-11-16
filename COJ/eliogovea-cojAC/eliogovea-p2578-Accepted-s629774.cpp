#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

struct obj {
	int m, v;
} a[2 * MAXN];

bool cmp(const obj &a, const obj &b) {
	if (a.m != b.m) return a.m < b.m;
	return a.v > b.v;
}

int n, k;
long long sol;
priority_queue<int> Q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i].m >> a[i].v;
	for (int i = 0; i < k; i++)
		cin >> a[n + i].m;
	sort(a, a + n + k, cmp);
	for (int i = 0; i < n + k; i++) {
		if (a[i].v) Q.push(a[i].v);
		else if (!Q.empty()) {
			sol += Q.top();
			Q.pop();
		}
	}
	cout << sol << '\n';
}
