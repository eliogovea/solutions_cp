#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 105;

typedef long long ll;

struct pt {
	ll x, y;
	bool operator < (const pt &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
} P[MAXN], l, r;

ll cross(const pt &a, const pt &b, const pt &o) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int n;
vector<pt> a, b;

int main() {
  //freopen("e.in", "r", stdin);
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> P[i].x >> P[i].y;
		sort(P, P + n);
		a.clear();
		b.clear();
		for (int i = 1; i < n - 1; i++)
			if (cross(P[0], P[n - 1], P[i]) <= 0) a.push_back(P[i]);
			else b.push_back(P[i]);
		cout << n << '\n';
		cout << P[0].x << ' ' << P[0].y << '\n';
		for (int i = 0; i < a.size(); i++)
			cout << a[i].x << ' ' << a[i].y << '\n';
		cout << P[n - 1].x << ' ' << P[n - 1].y << '\n';
		for (int i = b.size() - 1; i >= 0; i--)
			cout << b[i].x << ' ' << b[i].y << '\n';
	}
}
