#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1);

inline int sign(const double x) {
	return (x < -EPS) ? -1 : (x > EPS);
}

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

inline double cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline double signed_area(const vector <point> &G) {
	double area = 0.0;
	int n = G.size();
	for (int i = 0; i < n; i++) {
		int j = (i + 1 == n) ? 0 : i + 1;
		area += cross(G[i], G[j]);
	}
	return area * 0.5;
}

inline double abs_area(const vector <point> &G) {
	return abs(signed_area(G));
}

/// a * x + b * y + c = 0
struct line {
	double a, b, c;
	double angle;
	line() {}
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {
		set_angle(); /// !!!
	}
	line(point P, point Q) {
		double dx = Q.x - P.x;
		double dy = Q.y - P.y;
		double len = sqrt(dx * dx + dy * dy);
		dx /= len;
		dy /= len;
		a = -dy;
		b = dx;
		c = -(a * P.x + b * P.y); // c = -cross(point(Q - P, P));
		set_angle(); /// !!!
	}
	inline int side(const point &P) {
		return sign(a * P.x + b * P.y + c);
	}
	inline void set_angle() {
		angle = atan2(-a, b);
	}
};

inline point intersect(const line &a, const line &b) {
	double det = a.a * b.b - a.b * b.a;
	// assert(abs(det) > EPS); // !!!
	double det_x = (-a.c) * b.b - a.b * (-b.c);
	double det_y = a.a * (-b.c) - (-a.c) * b.a;
	return point(det_x / det, det_y / det);
}

vector <point> half_planes_intersection(vector <line> all) {
	const double INF = 1e9; /// segun el problema
	all.push_back(line(point(-INF, -INF), point(INF, -INF)));
	all.push_back(line(point(INF, -INF), point(INF, INF)));
	all.push_back(line(point(INF, INF), point(-INF, INF)));
	all.push_back(line(point(-INF, INF), point(-INF, -INF)));
	int n = all.size();
	sort(all.begin(), all.end(), [&](const line &a, const line &b) {
		if (sign(a.angle - b.angle) != 0) {
			return a.angle < b.angle;
		}
		return a.b < b.c;
	});

	int ptr = 1;
	for (int i = 1; i < n; i++) {
		if (sign(all[i].angle - all[ptr - 1].angle) == 0) {
			continue;
		}
		all[ptr++] = all[i];
	}

	if (ptr > 1 && sign(all[0].angle - all[ptr - 1].angle - 2.0 * PI) == 0) {
		if (all[ptr - 1].c < all[0].c) {
			swap(all[ptr - 1], all[0]);
		}
		ptr--;
	}
	all.resize(ptr);
	n = all.size();

	vector <line> Q(n);
	int head = 0;
	int tail = 0;
	for (int i = 0; i < n; i++) {
		while (head + 1 < tail && all[i].side(intersect(Q[tail - 2], Q[tail - 1])) != 1) {
			tail--;
		}
		while (head + 1 < tail && all[i].side(intersect(Q[head], Q[head + 1])) != 1) {
			head++;
		}
		Q[tail++] = all[i];
	}
	while (head + 1 < tail && Q[head].side(intersect(Q[tail - 1], Q[tail - 2])) != 1) {
		tail--;
	}
	while (head + 1 < tail && Q[tail - 1].side(intersect(Q[head], Q[head + 1])) != 1) {
		head++;
	} /// not sure

	vector <point> hull(tail - head);
	for (int i = head; i < tail; i++) {
		int j = (i + 1 == tail) ? head : i + 1;
		hull[i - head] = intersect(Q[i], Q[j]);
	}
	return hull;
}

// Contest 3 Campamento UCI 2017 (Gleb)
// Problem G
void test_1() {
	// freopen("in.txt", "r", stdin);

	int n;
	cin >> n;

	vector <point> G(n);
	for (int i = 0; i < n; i++) {
		cin >> G[i].x >> G[i].y;
	}

	reverse(G.begin(), G.end());

	int lo = 1;
	int hi = n - 2;
	int answer = hi;
	while (lo <= hi) {
		cerr << lo << " " << hi << "\n";
		int mid = (lo + hi) >> 1;
		vector <line> half_planes(n);
		for (int i = 0; i < n; i++) {
			int j = (i + mid + 1) % n;
			half_planes[i] = line(G[i], G[j]);
		}
		vector <point> hull = half_planes_intersection(half_planes);
		if (hull.size() < 3 || sign(abs_area(hull)) == 0) {
			answer = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	test_1();
}
