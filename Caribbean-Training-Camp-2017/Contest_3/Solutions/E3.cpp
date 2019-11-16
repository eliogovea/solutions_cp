#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(LL x) {
	if (x < 0) {
		return -1;
	}
	if (x > 0) {
		return 1;
	}
	return 0;
}

struct pt {
	LL x, y;
	pt() {}
	pt(LL _x, LL _y) : x(_x), y(_y) {};
};

pt operator + (const pt &a, const pt &b) {
    return pt(a.x + b.x, a.y + b.y);
}

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}


inline LL dot(const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

inline LL norm2(const pt &a) {
	return dot(a, a);
}

inline LL cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

bool operator < (const pt &a, const pt &b) {
	int c = sign(cross(a, b));
	return (c > 0);
}

bool operator != (const pt &a, const pt &b) {
	return (a < b) || (b < a);
}

inline bool isIn(int x, int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	return (a <= x && x <= b);
}

inline bool contains(pt p, pt a, pt b) {
	if (a.x == b.x && a.y == b.y) {
		return p.x == a.x && p.y == a.y;
	}
	if (sign(cross(a - p, b - p))) {
		return false;
	}
	return isIn(p.x, a.x, b.x) && isIn(p.y, a.y, b.y);
}

inline pt get(pt a) {
	if (a.y < 0) {
		a.x = -a.x;
		a.y = -a.y;
		return a;
	}
	if (a.y == 0 && a.x < 0) {
		a.x = -a.x;
	}
	return a;
}

const int N = 1000 + 10;

int n;
pt a[N], b[N];
bool in[N];

struct event {
	pt p, q;
	int type;
	int index;
	event() {}
	event(pt _p, pt _q, int _type, int _index) {
        p = _p;
        q = _q;
        type = _type;
        index = _index;
    }
};

bool operator < (const event &a, const event &b) {
	int c = sign(cross(a.p, b.p));
	if (c != 0) {
        return (c > 0);
	}
	return a.type < b.type;
}

int solve(pt c, int id, pt &p1, pt &p2) {

    for (int i = 0; i < n; i++) {
		in[i] = false;
	}
	int cnt = 1;
	p1 = c;
	p2 = p1; p2.x++;
	vector <event> e;
	for (int i = 0; i < n; i++) {
		if (i == id) {
			continue;
		}
		if (contains(c, a[i], b[i])) {
			cnt++;
		} else {
			pt pa = a[i] - c;
			pt pb = b[i] - c;
			if (cross(pa, pb) < 0) {
				swap(pa, pb);
			}
			e.push_back(event(get(pa), pa + c, -1, i));
			e.push_back(event(get(pb), pb + c, 1, i));
		}
	}
	sort(e.begin(), e.end());
	int mx = cnt;
	for (int i = 0; i < e.size(); i++) {
        if (e[i].type == -1) {
            if (!in[e[i].index]) {
                cnt++;
                in[e[i].index] = true;
                if (cnt > mx) {
                    mx = cnt;
                    p2 = e[i].q;
                }
            }
		} else {
			if (in[e[i].index]) {
				cnt--;
				in[e[i].index] = false;
			}
		}
	}
	for (int i = 0; i < e.size(); i++) {
        if (e[i].type == -1) {
            if (!in[e[i].index]) {
                cnt++;
                in[e[i].index] = true;
                if (cnt > mx) {
                    mx = cnt;
                    p2 = e[i].q;
                }
            }
		} else {
			if (in[e[i].index]) {
				cnt--;
				in[e[i].index] = false;
			}
		}
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input001.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
	}

	int ansc = 0;
	pt ans1, ans2;
	for (int i = 0; i < n; i++) {
		pt p1a, p2a;
		int cnta = solve(a[i], i, p1a, p2a);
		// cerr << "a " << i << " " << cnta << " " << p1a.x << " " << p1a.y << " " << p2a.x << " " << p2a.y << "\n";
		if (cnta > ansc) {
			ansc = cnta;
			ans1 = p1a;
			ans2 = p2a;
		}
		pt p1b, p2b;
		int cntb = solve(b[i], i, p1b, p2b);
		if (cntb > ansc) {
			ansc = cntb;
			ans1 = p1b;
			ans2 = p2b;
		}
	}

	cout << ans1.x << " " << ans1.y << " " << ans2.x << " " << ans2.y << "\n";
}
