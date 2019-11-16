#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct pt {
	int x, y;
	pt() {}
	pt(int a, int b) : x(a), y(b) {}
};

vector<pt> pts;

int cross(pt &a, pt &b, pt &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int n, sol;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] != '.') pts.push_back(pt(i, j));
	}
	int sz = pts.size();
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++)
				sol += (cross(pts[i], pts[j], pts[k]) == 0);
	cout << sol << "\n";
}
