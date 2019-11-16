#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

inline int sign(const double x) {
	return (x < -EPS) ? -1 : (x > EPS);
}

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) 
		: x(_x), y(_y) {}
};

point operator + (const point &P, const point &Q) {
	return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point &P, const double k) {
	return point(P.x * k, P.y * k);
}

inline double cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline point rot_90_ccw(const point &P) {
	return point(-P.y, P.x);
}

inline point rot_90_cw(const point &P) {
	return point(P.y, -P.x);
}

inline point intersect(const point &A, const point &B, const point &C, const point &D) {
	return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

inline double signed_area(const vector <point> &G) {
	int n = G.size();
	double area = 0.0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1 == n) ? 0 : i + 1;
		area += cross(G[i], G[j]);
	}
	return 0.5 * area;
}

inline double area(const vector <point> &G) {
	return abs(signed_area(G));
}


/// left side of PQ (Q - P)
vector <point> convex_cut(const vector <point> &G, const point &P, const point &Q) {
	int n = G.size();
	vector <point> res;
	for (int i = 0; i < n; i++) {
		int si = sign(cross(Q - P, G[i] - P));
		if (si >= 0) {
			res.push_back(G[i]);
		}
		int j = (i + 1 == n) ? 0 : i + 1;
		int sj = sign(cross(Q - P, G[j] - P));
		if (si * sj == -1) {
			res.push_back(intersect(P, Q, G[i], G[j]));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	
	const double L = 10.0;
	
	vector <point> G;
	G.push_back(point(0.0, 0.0));
	G.push_back(point(L, 0.0));
	G.push_back(point(L, L));
	G.push_back(point(0.0, L));
	
	string line;
	
	point P = point(0.0, 0.0);
	
	bool positive_area = true;
	
	while (getline(cin, line)) {
		stringstream in(line);
		point Q;
		string s;
		
		in >> Q.x >> Q.y >> s;
		
		if (!positive_area) {
			cout << "0.00\n";
			continue;
		}
		
		if (s == "Same") {
			positive_area = false;
			cout << "0.00\n";
			continue;
		}
		
		point M = (P + Q) * 0.5;
		point R = M + rot_90_ccw(Q - P);
		
		if (s == "Hotter") {
			G = convex_cut(G, R, M);
		} else {
			G = convex_cut(G, M, R);
		}
		
		if (G.size() < 3) {
			positive_area = false;
			cout << "0.00\n";
			continue;
		}
		
		P = Q;
		
		cout << fixed << area(G) << "\n";
	}
}