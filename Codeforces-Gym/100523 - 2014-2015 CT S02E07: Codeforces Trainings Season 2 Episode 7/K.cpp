// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523K

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct pt {
	LL x, y, z;
	pt() {}
	pt(LL _x, LL _y, LL _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y, a.z - b.z);
}

pt cross(const pt &a, const pt &b) {
	LL x = a.y * b.z - a.z * b.y;
	LL y = -(a.x * b.z - a.z * b.x);
	LL z = a.x * b.y - a.y * b.x;
	return pt(x, y, z);
}

LL dot(const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

const int N = 100005;

int n;
pt pts[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y >> pts[i].z;
	}
	if (n <= 3) {
		cout << "TAK\n";
		return 0;
	}
	bool oneLine = true;
	pt v1 = pts[1] - pts[0];
	for (int i = 2; i < n; i++) {
		pt v2 = pts[i] - pts[0];
		pt v3 = cross(v1, v2);
		if (v3.x != 0 || v3.y != 0 || v3.z != 0) {
			oneLine = false;
			break;
		}
	}
	if (oneLine) {
		cout << "TAK\n";
		return 0;
	}
	pt v;
	for (int i = 2; i < n; i++) {
		pt v2 = pts[i] - pts[0];
		pt v3 = cross(v1, v2);
		if (v3.x != 0 || v3.y != 0 || v3.z != 0) {
			v = v3;
			break;
		}
	}
	LL g = __gcd(abs(v.x), __gcd(abs(v.y), abs(v.z)));
	v.x /= g;
	v.y /= g;
	v.z /= g;
	bool onePlane = true;
	for (int i = 1; i < n; i++) {
		if (dot(pts[i] - pts[0], v) != 0) {
			onePlane = false;
			break;
		}
	}
	cout << (onePlane ? "TAK" : "NIE") << "\n";
}
