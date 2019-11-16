// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497I

#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

struct pt {
	int x, y, f, id;
};

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.id < b.id;
}

bool cmp(const pt &a, const pt &b) {
    return a.id < b.id;
}


int n, k;
pt pts[N];

int dp[N];
int trace[N];

int X, Y;

map <int, pair <int, int> > fila, col;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y >> pts[i].f;
		pts[i].id = i;
		dp[i] = -1;
		trace[i] = -1;
	}
	X = pts[0].x;
	Y = pts[0].y;
	dp[0] = pts[0].f;
	fila[pts[0].y] = col[pts[0].x] = make_pair(pts[0].id, pts[0].f);
	sort(pts, pts + n);
	for (int i = 0; i < n; i++) {
		if (pts[i].id == 0) {
			continue;
		}
		if (pts[i].x < X || pts[i].y < Y) {
			continue;
		}
		map <int, pair <int, int> >::iterator a = fila.find(pts[i].y);
		map <int, pair <int, int> >::iterator b = col.find(pts[i].x);
		if (a == fila.end() && b == col.end()) {
			continue;
		}
		if (a == fila.end() && b != col.end()) {
			int pos = b->second.first;
			int val = b->second.second;
			if (val >= k) {
				dp[pts[i].id] = val - k + pts[i].f;
				trace[pts[i].id] = pos;
			}
		}
		if (a != fila.end() && b == col.end()) {
			int pos = a->second.first;
			int val = a->second.second;
			if (val >= k) {
				dp[pts[i].id] = val - k + pts[i].f;
				trace[pts[i].id] = pos;
			}
		}
		if (a != fila.end() && b != fila.end()) {
			if (a->second.second > b->second.second) {
				int pos = a->second.first;
				int val = a->second.second;
				if (val >= k) {
					dp[pts[i].id] = val - k + pts[i].f;
					trace[pts[i].id] = pos;
				}
			} else {
				int pos = b->second.first;
				int val = b->second.second;
				if (val >= k) {
					dp[pts[i].id] = val - k + pts[i].f;
					trace[pts[i].id] = pos;
				}
			}
		}
		if (a == fila.end() || a->second.second < dp[pts[i].id]) {
			fila[pts[i].y] = make_pair(pts[i].id, dp[pts[i].id]);
		}
		if (b == col.end() || b->second.second < dp[pts[i].id]) {
			col[pts[i].x] = make_pair(pts[i].id, dp[pts[i].id]);
		}
	}
	cout << dp[n - 1] << "\n";
	int cur = n - 1;
	vector <int> ans;
	while (cur != -1) {
		ans.push_back(cur);
		cur = trace[cur];
	}
	assert(ans.back() == 0);
	sort(pts, pts + n, cmp);
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << pts[ans[i]].x << " " << pts[ans[i]].y << "\n";
	}
}
