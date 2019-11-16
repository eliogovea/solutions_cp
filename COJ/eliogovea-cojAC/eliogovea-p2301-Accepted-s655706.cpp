#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, q, v, x[3], y[3], sol;
int minx[MAXN], miny[MAXN], maxx[MAXN], maxy[MAXN];
char ch, aux;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[0] >> y[0]
				>> x[1] >> y[1]
				>> x[2] >> y[2];
    maxx[i] = max(x[0], max(x[1], x[2]));
    maxy[i] = max(y[0], max(y[1], y[2]));
    minx[i] = min(x[0], min(x[1], x[2]));
    miny[i] = min(y[0], min(y[1], y[2]));
	}
	sort(minx, minx + n);
	sort(miny, miny + n);
	sort(maxx, maxx + n);
	sort(maxy, maxy + n);

	cin >> q;
	while (q--) {
		cin >> ch >> aux >> v;
		if (ch == 'x') {
			sol = (lower_bound(minx, minx + n, v) - minx) -
                  (upper_bound(maxx, maxx + n, v) - maxx);
			cout << sol <<  "\n";
		}
		else {
			sol = (lower_bound(miny, miny + n, v) - miny) -
                  (upper_bound(maxy, maxy + n, v) - maxy);
			cout << sol << "\n";
		}
	}
}
