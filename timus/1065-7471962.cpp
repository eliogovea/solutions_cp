// Problem: pace=1&num=1065
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

inline int sign(long long x) {
	return (x < 0) ? -1 : (x > 0);
}

struct point {
	long long x, y;
	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {}
};

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

inline long long cross(const point &P, const point &Q) {
	return (long long)P.x * Q.y - (long long)P.y * Q.x;
}

inline double dist(const point &P, const point &Q) {
	double dx = P.x - Q.x;
	double dy = P.y - Q.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector <point> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	reverse(a.begin(), a.end()); // ccw
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
	}

	const double INF = 1e18;
	vector <vector <double> > graph(n, vector <double> (n, INF));
	for (int i = 0; i < n; i++) {
		int val;
		if (m != 0) {
			point P = b[0] - a[i];
			for (int j = 1; j < m; j++) {
				if (sign(cross(b[j] - a[i], P)) == 1) {
					P = b[j] - a[i];
				}
			}
			int lo = 1;
			int hi = n - 2;
			val = 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (sign(cross(a[(i + mid) % n] - a[i], P)) > 0) {
					val = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
		} else {
			val = n - 2;
		}
		// cerr << i << " " << val << "\n";
		for (int x = 0; x <= val; x++) {
			graph[i][(i + x) % n] = dist(a[i], a[(i + x) % n]);
		}
	}

	/// floyd
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	double answer = 0.0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		answer += dist(a[i], a[j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (sign(cross(a[j] - a[i], a[k] - a[i])) == 1) {
					double length = graph[i][j] + graph[j][k] + graph[k][i];
					// cerr << i << " " << j <<  " " << k << " " << length << "\n";
					answer = min(answer, graph[i][j] + graph[j][k] + graph[k][i]);
				}
			}
		}
	}

	cout.precision(2);
	cout << fixed << answer << "\n";
}


/*
5 2
8 9
0 -7
-8 -7
-8 1
-8 9
-4 -3
-1 -5
*/
