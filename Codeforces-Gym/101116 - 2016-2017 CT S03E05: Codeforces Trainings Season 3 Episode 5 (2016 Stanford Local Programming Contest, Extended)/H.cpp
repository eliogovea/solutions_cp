// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116H

#include <bits/stdc++.h>

using namespace std;

struct pt {
	int x, y;
	pt() {}
	pt(int _x, int _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

bool operator < (const pt &a, const pt &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <pt> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		int area = 0;
		for (int i = 1; i + 1 < n; i++) {
            area += cross(p[i] - p[0], p[i + 1] - p[0]);
		}
		cout << (area > 0 ? "fight" : "run") << "\n";
	}
}
