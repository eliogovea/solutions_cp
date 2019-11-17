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

/// !!! no se como mantener los puntos colineales del convex hull
/// not tested
vector <point> convex_hull_graham_scan(vector <point> pts) {
	sort(pts.begin(), pts.end());
	int n = pts.size();
	sort(++pts.begin(), pts.end(), compare_angle(pts[0]));
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

int count_commont_tangents(point C1, LL r1, point C2, LL r2) {
	LL d2 = dist2(C1, C2);
	// if (r1 > r2) {
		// swap(C1, C2);
		// swap(r1, r2);
	// }
	if (d2 > (r1 + r2) * (r1 + r2)) {
		return 4;
	}
	if (d2 == (r1 + r2) * (r1 + r2)) {
		return 3;
	}
	if (d2 < (r1 - r2) * (r1 - r2)) {
		return 0;
	}
	if (d2 == (r1 - r2) * (r1 - r2)) {
		return 1;
	}
	return 2;
}

void normalize_convex(vector <point> &polygon) {
	polygon.erase(unique(polygon.begin(), polygon.end()), polygon.end());
	while (polygon.size() > 1 && polygon[0] == polygon.back()) {
		polygon.pop_back();
	}
	rotate(polygon.begin(), min_element(polygon.begin(), polygon.end()), polygon.end());
	int ptr = 1;
	for (int i = 1; i < polygon.size(); i++) {
		if (is_in(polygon[i], polygon[i - 1], polygon[i + 1 == polygon.size() ? 0 : i + 1]));
		polygon[ptr++] = polygon[i];
	}
	polygon.resize(ptr);
}

// apply normalize_convex before
inline int inside_convex(const point &P, const vector <point> &polygon) {
	int n = polygon.size();
	assert(n >= 3);
	if (cross(P - polygon[0], polygon[1] - polygon[0]) > 0) {
		return OUT;
	}
	if (cross(polygon[n - 1] - polygon[0], P - polygon[0]) > 0) {
		return OUT;
	}
	if (cross(P - polygon[0], polygon[1] - polygon[0]) == 0) {
		return (is_in(P, polygon[0], polygon[1]) ? ON : OUT);
	}
	if (cross(polygon[n - 1] - polygon[0], P - polygon[0]) == 0) {
		return (is_in(P, polygon[0], polygon[n - 1]) ? ON : OUT);
	}
	int lo = 2;
	int hi = n - 1;
	int pos = hi;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (cross(P - polygon[0], polygon[mid] - polygon[0]) >= 0) {
			pos = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	int s = sign(cross(polygon[pos] - polygon[pos - 1], P - polygon[pos - 1]));
	if (s == 0) {
		return ON;
	}
	return ((s > 0) ? IN : OUT);
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
// test ok
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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// test OK
void test_counter_clockwise() {
	point A, B;
	cin >> A.x >> A.y >> B.x >> B.y;
	int q;
	cin >> q;
	while (q--) {
		point C;
		cin >> C.x >> C.y;
		int s = sign(cross(B - A, C - A));
		if (s != 0) {
			cout << ((s > 0) ? "COUNTER_CLOCKWISE" : "CLOCKWISE") << "\n";
		} else {
			if (dot(B - A, C - A) < 0) {
				cout << "ONLINE_BACK\n";
			} else {
				cout << (dist2(A, B) < dist2(A, C) ? "ONLINE_FRONT" : "ON_SEGMENT") << "\n";
			}
		}
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/status.jsp#submit/CGL_7/A
// test ???
void test_count_common_tangents() {
	point C1, C2;
	LL r1, r2;
	cin >> C1.x >> C1.y >> r1 >> C2.x >> C2.y >> r2;
	int answer = count_commont_tangents(C1, r1, C2, r2);
	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// test_segment_segment_intersection();
	// test_is_convex();
	// test_point_inside_polygon();
	// test_parallel_orthogonal();
	// test_convex_hull();
	// test_counter_clockwise();
	test_count_common_tangents();
}

