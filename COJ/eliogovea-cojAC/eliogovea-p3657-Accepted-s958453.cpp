#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD EPS = 1e-11;

struct pt {
	LD x, y;
	pt() {}
	pt(LD _x, LD _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline LD dist2(const pt &a, const pt &b) {
	LD dx = a.x - b.x;
	LD dy = a.y - b.y;
	return dx * dx + dy * dy;
}

inline LD getAngle(const pt &P) {
	if (abs(P.x) < EPS) {
		return (P.y > 0.0 ? M_PI / 2.0 : 3.0 * M_PI / 2.0);
	}
	if (abs(P.y) < EPS) {
		return (P.x > 0.0 ? 0.0 : M_PI);
	}
	LD angle = atan(abs(P.y) / abs(P.x));
	if (P.x > 0.0 && P.y > 0.0) {
		return angle;
	}
	if (P.x < 0.0 && P.y > 0.0) {
		return M_PI - angle;
	}
	if (P.x < 0.0 && P.y < 0.0) {
		return M_PI + angle;
	}
	return 2.0 * M_PI - angle;
}

const int N = 5005;

int n;
pt pts[N];

int ncc;
int cc[N];
int size[N];

struct event {
	LD angle;
	int id;
	event() {}
	event(LD _angle, int _id) : angle(_angle), id(_id) {}
};

bool operator < (const event &a, const event &b) {
	if (abs(a.angle - b.angle) > EPS) {
		return a.angle < b.angle;
	}
	return a.id < b.id;
}

int freq[N];

inline void add(int id, int &cur) {
	if (freq[cc[id]] == 0) {
		cur += size[cc[id]];
	}
	freq[cc[id]]++;
}

inline void sub(int id, int &cur) {
	if (freq[cc[id]] == 1) {
		cur -= size[cc[id]];
	}
	freq[cc[id]]--;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	/// reading
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}

	/// cc
	for (int i = 0; i < n; i++) {
		cc[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (cc[i] == -1) {
			queue <int> Q;
			Q.push(i);
			cc[i] = ncc;
			size[ncc] = 1;
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (int to = 0; to < n; to++) {
					if ((dist2(pts[u], pts[to]) <= 4.0 + EPS) && cc[to] == -1) {
						cc[to] = ncc;
						size[ncc]++;
						Q.push(to);
					}
				}
			}
			ncc++;
		}
	}
	int ans = 0;
	///
	for (int i = 0; i < n; i++) {
		vector <int> v;
		for (int j = 0; j < n; j++) {
			if (cc[j] != cc[i] && (dist2(pts[i], pts[j]) <= 16.0 + EPS)) {
				v.push_back(j);
			}
		}
		if ((int)v.size() == 0) {
			ans = max(ans, size[cc[i]] + 1);
			continue;
		}
		for (int i = 0; i < ncc; i++) {
			freq[i] = 0;
		}
		vector <event> events;
		int cur = size[cc[i]] + 1;
		ans = max(ans, cur);
		for (int j = 0; j < v.size(); j++) {
			LD d2 = dist2(pts[i], pts[v[j]]);
			LD d = sqrt(d2);
			LD h = sqrt(max((LD)0.0, 4.0 - d2 / 4.0));
			LD xx = h * (pts[v[j]] - pts[i]).x / d;
			LD yy = h * (pts[v[j]] - pts[i]).y / d;
			LD xx1 = (pts[v[j]] - pts[i]).x / 2.0 + yy;
			LD yy1 = (pts[v[j]] - pts[i]).y / 2.0 - xx;
			LD angle1 = getAngle(pt(xx1, yy1));
			LD xx2 = (pts[v[j]] - pts[i]).x / 2.0 - yy;
			LD yy2 = (pts[v[j]] - pts[i]).y / 2.0 + xx;
			LD angle2 = getAngle(pt(xx2, yy2));
			if (angle2 < angle1) {;
				add(v[j], cur);
			}
			events.push_back(event(angle1, -v[j] - 1));
			events.push_back(event(angle2, v[j] + 1));
		}
		ans = max(ans, cur);
		sort(events.begin(), events.end());
		for (int j = 0; j < events.size(); j++) {
			if (events[j].id < 0) {
				add(-(events[j].id + 1), cur);
			} else {
				sub(events[j].id - 1, cur);
			}
			ans = max(ans, cur);
		}
	}
	cout << ans << "\n";
}
