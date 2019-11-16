// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112G

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int w, n;
vector <pair <pair <LL, LL>, LL> > v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> n;
	LL x1, y1, x2, y2, dx, dy;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		dx = x1 - x2;
		dy = y1 - y2;
		LL a = -dy;
		LL b = dx;
		LL c = -(a * x1 + b * y1);
		if (a < 0LL) {
			a = -a; b = -b; c = -c;
		} else if (a == 0LL) {
			if (b < 0LL) {
				b = -b; c = -c;
			} else if (b == 0LL && c < 0LL) {
				c = -c;
			}
		}
		//cout << a << " " << b << " " << c << "\n";
		LL g = __gcd(abs(a), __gcd(abs(b), abs(c)));
		a /= g;
		b /= g;
		c /= g;
		v.push_back(make_pair(make_pair(a, b), c));
		//cout << i << " " << a << " " << b << " " << c << "\n";
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int t = 0;
	LL a = v[0].first.first;
	LL b = v[0].first.second;
	LL g = __gcd(abs(a), abs(b));
	a /= g;
	b /= g;
	bool p = true;
	for (int i = 1; i < v.size(); i++) {
		g = __gcd(abs(v[i].first.first), abs(v[i].first.second));
		v[i].first.first /= g;
		v[i].first.second /= g;
		if (v[i].first.first != a || v[i].first.second != b) {
            p = false;
            break;
		}
	}
	if (p) {
		t = v.size() + 1;
	} else {
		t = 2 * v.size();
	}
	//cout << t << "\n";
	if (t >= w) {
		cout << "0\n";
	} else {
		int ans = 1;
		while (2 * (v.size() + ans) < w) ans++;
		cout << ans << "\n";
	}
}
