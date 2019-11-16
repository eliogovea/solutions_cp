// Problem: pace=1&num=1010
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(const LL x) {
	return (x < 0) ? -1 : (x > 0);
}

struct point {
	LL x, y;
	point(LL _x = 0, LL _y = 0) : x(_x), y(_y) {}
};

point operator - (const point &P, const point &Q) {
	return point(P.x - Q.x, P.y - Q.y);
}

LL cross(const point &P, const point &Q) {
	return P.x * Q.y - P.y * Q.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector <point> pts(n);
	for (int i = 0; i < n; i++) {
		pts[i].x = i;
		cin >> pts[i].y;
	}
	
	int ans_id = 0;
	point ans_v = pts[1] - pts[0];
	if (ans_v.y < 0) {
		ans_v.y = -ans_v.y;
	}
	
	for (int i = 1; i + 1 < n; i++) {
		point v = pts[i + 1] - pts[i];
		if (v.y < 0) {
			v.y = -v.y;
		}
		if (sign(cross(ans_v, v)) == 1) {
			ans_id = i;
			ans_v = v;
		}
	}
	
	cout << ans_id + 1 << " " << ans_id + 2 << "\n";
	
	// vector <int> id(n);
	// int top = 0;
	
	// for (int i = 0; i < n; i++) {
		// while (top > 1 && sign(cross(pts[id[top - 1]] - pts[id[top - 2]], pts[i] - pts[id[top - 2]])) > 0) {
			// top--;
		// }
		// id[top++] = i;
	// }
	
	// int ans_id = 0;
	// point ans_v = pts[id[1]] - pts[id[0]];
	// for (int i = 1; i + 1 < top; i++) {
		// point v = pts[id[i + 1]] - pts[id[i]];
		// if (v.y < 0) {
			// v.y = -v.y;
		// }
		// if (sign(cross(ans_v, v)) == 1) {
			// ans_id = i;
			// ans_v = v;
		// }
	// }
	
	// cout << id[ans_id] + 1 << " " << id[ans_id + 1] + 1 << "\n";
}

