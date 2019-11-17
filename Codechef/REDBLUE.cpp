// https://www.codechef.com/DEC17/problems/REDBLUE

#include <bits/stdc++.h>

using namespace std;

inline int sign(long long x) {
	return (x < 0) ? -1 : (x > 0);
}

struct point {
	int x, y;
	point() {}
	point(int _x, int _y) : x(_x), y(_y) {}
};

point operator - (const point & P, const point & Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

inline long long cross(const point & P, const point & Q) {
	return (long long)P.x * Q.y - (long long)P.y * Q.x;
}

point fix(point P) {
	if (P.y < 0 || (P.y == 0 && P.x < 0)) {
		P.x = -P.x;
		P.y = -P.y;
	}
	return P;
}

const int N = 1000 + 10;

int n, m;
point pts[N + N];
int color[N + N];

struct event {
	point P;
	int c;
	int v;
	event() {}
	event(point _P, int _c, int _v) : P(_P), c(_c), v(_v) {}
};

bool operator < (const event & a, const event & b) {
	return (cross(a.P, b.P) > 0);
}

event E[N + N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
		color[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> pts[n + i].x >> pts[n + i].y;
		color[n + i] = 1;
	}

	int answer = n - 1 + m - 1;

	for (int id = 0; id < n + m; id++) {
		point P = pts[id];
		// cerr << "center: " << P.x << " " << P.y << "\n";
		{
			// cerr << "start ccw sweep\n";
			int pos = 0;
			int red_left = 0;
			int blue_left = 0;
			for (int i = 0; i < n + m; i++) {
				if (i != id) {
					point Q = pts[i] - P;
					if (Q.y >= 0) {
						if (i < n) {
							red_left++;
						} else {
							blue_left++;
						}
					}
					if (Q.y > 0 || (Q.y == 0 && Q.x > 0)) {
						E[pos++] = event(fix(Q), color[i], -1);
					} else if (Q.y < 0) {
						E[pos++] = event(fix(Q), color[i], 1);
					}
				}
			}
			if (id < n) {
				red_left++;
			} else {
				blue_left++;
			}
			sort(E, E + pos);
			int best = min(red_left + m - blue_left, blue_left + n - red_left);
			// cerr << "-->> " << red_left << " " << blue_left << " " << best << "\n";
			for (int i = 0; i < pos; i++) {
				if (E[i].c == 0) {
					red_left += E[i].v;
				} else {
					blue_left += E[i].v;
				}
				best = min(best, min(red_left + m - blue_left, blue_left + n - red_left));
				// cerr << "-->> " << "(" << E[i].P.x << ", " << E[i].P.y << ") " << red_left << " " << blue_left << " " << best << "\n";
			}
			answer = min(answer, best);
		}
		{
			// cerr << "start cw sweep\n";
			int pos = 0;
			int red_left = 0;
			int blue_left = 0;
			for (int i = 0; i < n + m; i++) {
				if (i != id) {
					point Q = P - pts[i];
					// cerr << "Q: " << Q.x << " " << Q.y << "\n";
					if (Q.y >= 0) {
						if (i < n) {
							red_left++;
						} else {
							blue_left++;
						}
					}
					if (Q.y > 0 || (Q.y == 0 && Q.x > 0)) {
						E[pos++] = event(fix(Q), color[i], -1);
					} else if (Q.y < 0) {
						E[pos++] = event(fix(Q), color[i], 1);
					}
				}
			}
			if (id < n) {
				red_left++;
			} else {
				blue_left++;
			}
			sort(E, E + pos);
			int best = min(red_left + m - blue_left, blue_left + n - red_left);
			// cerr << "-->> " << red_left << " " << blue_left << " " << best << "\n";
			for (int i = 0; i < pos; i++) {
				if (E[i].c == 0) {
					red_left += E[i].v;
				} else {
					blue_left += E[i].v;
				}
				// cerr << "-->> " << "(" << E[i].P.x << ", " << E[i].P.y << ") " << red_left << " " << blue_left << " " << best << "\n";
				best = min(best, min(red_left + m - blue_left, blue_left + n - red_left));
			}
			answer = min(answer, best);
		}
	}
	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

