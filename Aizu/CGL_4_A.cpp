/// Geometry INT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(const LL x) {
	if (x < 0) {
		return -1;
	}
	if (x > 0) {
		return 1;
	}
	return 0;
}

struct point {
	LL x, y;
	point() {}
	point(LL _x, LL _y) : x(_x), y(_y) {}
};

bool operator < (const point &P, const point &Q) {
	if (P.y != Q.y) {
		return P.y < Q.y;
	}
	return P.x < Q.x;
}

bool operator == (const point &P, const point &Q) {
	return !(P < Q) && !(Q < P);
}

struct compare_x {
	bool operator () (const point &P, const point &Q) {
		if (P.x != Q.x) {
			return P.x < Q.x;
		}
		return P.y < Q.y;
	}
};

void normalize(point &P) {
	assert(P.x != 0 || P.y != 0);
	LL g = __gcd(abs(P.x), abs(P.y));
	P.x /= g;
	P.y /= g;
	if (P.x < 0 || (P.x == 0 && P.y < 0)) {
		P.x = -P.x;
		P.y = -P.y;
	}
}

inline int half_plane(const point &P) {
	if (P.y != 0) {
		return sign(P.y);
	}
	return sign(P.x);
}

point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point &P, const point &Q) {
	return point (P.x - Q.x, P.y - Q.y);
}

point operator * (const point &P, const LL k) {
	return point(P.x * k, P.y * k);
}

point operator / (const point &P, const LL k) {
	assert(k != 0 && P.x % k == 0 && P.y % k == 0);
	return point(P.x / k, P.y / k);
}

inline LL dot(const point &P, const point &Q) {
	return P.x * Q.x + P.y * Q.y;
}

inline LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline LL dist2(const point &P, const point &Q) {
	LL dx = P.x - Q.x;
	LL dy = P.y - Q.y;
	return dx * dx + dy * dy;
}

inline bool is_in(LL x, LL a, LL b) {
	if (a > b) {
		swap(a, b);
	}
	return (a <= x && x <= b);
}

inline bool is_in(const point &P, const point &A, const point &B) {
	if (cross(B - A, P - A) != 0) {
		return false;
	}
	return (is_in(P.x, A.x, B.x) && is_in(P.y, A.y, B.y));
}

inline bool segment_segment_intersect(const point &A, const point &B, const point &C, const point &D) {
	if (cross(B - A, D - C) == 0) { // lines are parallel
		return (is_in(A, C, D) || is_in(B, C, D) || is_in(C, A, B) || is_in(D, A, B));
	}
	if (sign(cross(C - A, B - A)) * sign(cross(D - A, B - A)) > 0) {
		return false;
	}
	if (sign(cross(A - C, D - C)) * sign(cross(B - C, D - C)) > 0) {
		return false;
	}
	return true;
}

inline bool is_convex(const vector <point> &polygon) {
	int n = polygon.size();
	assert(n >= 3);
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		int k = (i + 2) % n;
		if (sign(cross(polygon[j] - polygon[i], polygon[k] - polygon[i])) < 0) {
			return false;
		}
	}
	return true;
}

const int OUT = 0;
const int ON = 1;
const int IN = 2;
/// 0 outside, 1 boundary, 2 inside
inline int point_inside_polygon(const point &P, const vector <point> &polygon) {
	int n = polygon.size();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		point A = polygon[i];
		point B = polygon[(i + 1) % n];
		if (is_in(P, A, B)) {
			return ON;
		}
		if (B.y < A.y) {
			swap(A, B);
		}
		if (P.y < A.y || B.y <= P.y || A.y == B.y) {
			continue;
		}
		if (sign(cross(B - A, P - A)) > 0) {
			cnt++;
		}
	}
	if (cnt & 1) {
		return IN;
	}
	return OUT;
}

struct compare_angle {
	point O;
	compare_angle() {}
	compare_angle(point _O) {
		O = _O;
	}
	bool operator () (const point &P, const point &Q) {
		if (half_plane(P - O) != half_plane(Q - O)) {
			return half_plane(P - O) < half_plane(Q - O);
		}
		int c = sign(cross(P - O, Q - O));
		if (c != 0) {
			return (c > 0);
		}
		return dist2(P, O) < dist2(Q, O);
	}
};

/// !!! no se como mantener los puntos colineales
vector <point> convex_hull_graham_scan(vector <point> pts) {
	sort(pts.begin(), pts.end());
	int n = pts.size();
	if (n <= 3) {
		return pts;
	}
	sort(++pts.begin(), pts.end(), compare_angle(pts[0]));

	cerr << "DEBUG\n";
	for (int i = 0; i < n; i++) {
		cerr << pts[i].x << " " << pts[i].y << "\n";
	}

	vector <point> ch(n);
	int top = 0;
	for (int i = 0; i < n; i++) {
		while (top >= 2 && cross(ch[top - 1] - ch[top - 2], pts[i] - ch[top - 2]) < 0) {
			top--;
		}
		ch[top++] = pts[i];
	}
	ch.resize(top);
	return ch;
}

vector <point> convex_hull_monotone_chain(vector <point> pts) {
	sort(pts.begin(), pts.end());
	int n = pts.size();
	vector <point> ch(2 * n);
	int top = 0;
	for (int i = 0; i < n; i++) {
		while (top >= 2 && cross(ch[top - 1] - ch[top - 2], pts[i] - ch[top - 2]) < 0) {
			top--;
		}
		ch[top++] = pts[i];
	}
	int size = top;
	for (int i = n - 2; i >= 0; i--) {
		while (top - size >= 1 && cross(ch[top - 1] - ch[top - 2], pts[i] - ch[top - 2]) < 0) {
			top--;
		}
		ch[top++] = pts[i];
	}
	if (ch[0] == ch[top - 1]) {
		top--;
	}
	ch.resize(top);
	return ch;
}

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
// test OK
void test_segment_segment_intersection() {
	int q;
	cin >> q;
	while (q--) {
		point A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		cout << (segment_segment_intersect(A, B, C, D) ? "1" : "0") << "\n";
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// test OK
void test_is_convex() {
	int n;
	cin >> n;
	vector <point> polygon(n);
	for (int i = 0; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}
	cout << (is_convex(polygon) ? "1" : "0") << "\n";
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
// test OK
void test_point_inside_polygon() {
	int n;
	cin >> n;
	vector <point> polygon(n);
	for (int i = 0; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}
	int q;
	cin >> q;
	while (q--) {
		point P;
		cin >> P.x >> P.y;
		cout << point_inside_polygon(P, polygon) << "\n";
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// test ok
void test_parallel_orthogonal() {
	int q;
	cin >> q;
	while (q--) {
		point A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		int answer = 0;
		if (cross(B - A, D - C) == 0) {
			answer = 2;
		} else if (dot(B - A, D - C) == 0) {
			answer = 1;
		}
		cout << answer << "\n";
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// test ???
void test_convex_hull() {
	int n;
	cin >> n;
	vector <point> pts(n);
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}
	vector <point> answer = convex_hull_monotone_chain(pts);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].x << " " << answer[i].y << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// test_segment_segment_intersection();
	// test_is_convex();
	// test_point_inside_polygon();
	// test_parallel_orthogonal();
	test_convex_hull();
}

