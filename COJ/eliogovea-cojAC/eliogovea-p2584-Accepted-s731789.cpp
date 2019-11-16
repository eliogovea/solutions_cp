#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <climits>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

int n;

struct pt {
	int x;
	int y;
	pt() {}
	pt(int a, int b) {
		x = a; y = b;
	}
} p[305];

int cross(const pt &a, const pt &b, const pt &c) {
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}

double ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			int ap = 0, an = 0;
			for (int k = 0; k < n; k++) {
				int c = cross(p[i], p[j], p[k]);
				if (c == 0) continue;
				if (c > 0 && c > ap) ap = c;
				if (c < 0 && -c > an) an = -c;
			}
			if (ap == 0 || an == 0) continue;
			if (ans < ap + an) ans = ap + an;
		}
	cout.precision(2);
	cout << fixed << ans / 2.0 << "\n";
}
