// 2014 Benelux Algorithm Programming Contest (BAPC 14), 2014-2015 CT S02E08: Codeforces Trainings Season 2 Episode 8
// 100526I

#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;

vector <LL> g;

const int INF = 1e9;

LL t, n;

LL egcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	LL x1, y1;
	LL g = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

void solve(LL a, LL b, LL c, LL &x, LL &y) {
	LL g = egcd(a, b, x, y);
	assert(g == 1);
	c /= g;
	x = x * c;
	y = y * c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	LL x = 1;
	LL y = 1;
	g.push_back(x);
	g.push_back(y);
	while (x + y <= INF) {
		g.push_back(x + y);
		int tmp = x + y;
		x = y;
		y = tmp;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		int ansx = 1;
		int ansy = n - 1;
		for (int i = 0; g[i + 1] <= n && i + 1 < g.size(); i++) {
			LL x, y;
			solve(g[i], g[i + 1], n, x, y);
			//cout << g[i] << " " << g[i + 1] << " " << x << " " << y << " ==> ";
			if (y <= 0) {
				int cnty = -y / g[i] + 1;
				y += cnty * g[i];
				x -= cnty * g[i + 1];
			}
            if (x <= 0) {
                int cntx = -x / g[i + 1] + 1;
                y -= cntx * g[i];
                x += cntx * g[i + 1];
                if (y <= 0) continue;
            }

            /*while (x > y) {
                x -= g[i + 1];
                y += g[i];
            }*/
            if (x > y) {
                LL k = (x - y) / (g[i] + g[i + 1]) + 1;
                x -= g[i + 1] * k;
                y += g[i] * k;
            }
            if (x < y) {
                LL k = (y - x) / (g[i] + g[i + 1]);
                x += g[i + 1] * k;
                y -= g[i] * k;
            }
            //assert(x <= y);
			//cout << g[i] << " " << g[i + 1] << " " << x << " " << y << "\n";
			if ((x < n) && (y < n) && (x <= y) && (x > 0) && (y > 0) && ((y < ansy) || (y == ansy && x < ansx))) {
				//cout << x << " " << y << "\n";
				ansx = x;
				ansy = y;
			}
		}
		cout << ansx << " " << ansy << "\n";
	}
}
