#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct point {
	LL x, y;
	point() {}
	point(LL _x, LL _y) : x(_x), y(_y) {}
};

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

inline LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

inline double dist(const point &P, const point &Q) {
	double dx = P.x - Q.x;
	double dy = P.y - Q.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	
	int n, m;
	cin >> n >> m;
	
	vector <point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	
	reverse(a.begin(), a.end());
	
	vector <point> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
	}
	
	if (m == 0) {
		double answer = 1e17;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (cross(a[j] - a[i], a[k] - a[i]) != 0) {
						answer = min(answer, dist(a[i], a[j]) + dist(a[j], a[k]) + dist(a[k], a[i]));
					}
				}
			}
		}
		cout << fixed << answer << "\n";
		return 0;
	}
	
	vector <point> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = b[0];
		for (int j = 1; j < m; j++) {
			if (cross(b[j] - a[i], c[i] - a[i]) > 0) {
				c[i] = b[j];
			}
		}
	}
	
	vector <vector <double> > graph(n, vector <double> (n, 1e17));
	
	for (int i = 0; i < n; i++) {
		graph[i][i] = 0.0;
	}
	
	for (int i = 0; i < n; i++) {
		int j = i + 1 == n ? 0 : i + 1;
		while (cross(a[j] - a[i], c[i] - a[i]) > 0) {
			graph[i][j] = dist(a[i], a[j]);
			j = j + 1 == n ? 0 : j + 1;
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	double answer = 1e17;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (cross(a[j] - a[i], a[k] - a[i]) != 0) {
					answer = min(answer, graph[i][j] + graph[j][k] + graph[k][i]);
				}
			}
		}
	}
	
	cout << fixed << answer << "\n";
}