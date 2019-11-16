#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, q, v, x[3], y[3], sol;
int minx[MAXN], miny[MAXN], maxx[MAXN], maxy[MAXN];
char ch[2], aux[2];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
    maxx[i] = max(x[0], max(x[1], x[2]));
    maxy[i] = max(y[0], max(y[1], y[2]));
    minx[i] = min(x[0], min(x[1], x[2]));
    miny[i] = min(y[0], min(y[1], y[2]));
	}
	sort(minx, minx + n);
	sort(miny, miny + n);
	sort(maxx, maxx + n);
	sort(maxy, maxy + n);

	scanf("%d", &q);
	while (q--) {
      scanf("%s%s%d", ch, aux, &v);
		if (ch[0] == 'x') {
			sol = (lower_bound(minx, minx + n, v) - minx) -
                  (upper_bound(maxx, maxx + n, v) - maxx);
			printf("%d\n", sol);
		} else {
			sol = (lower_bound(miny, miny + n, v) - miny) -
                  (upper_bound(maxy, maxy + n, v) - maxy);
			printf("%d\n", sol);
		}
	}
}
