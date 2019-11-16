#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, c, h[N], hh[N], ini, ans;

int f(int x) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (x > h[i]) {
			hh[i] = x;
			ret += (x - h[i]) * (x - h[i]);
		} else {
			hh[i] = h[i];
		}
		if (i != 1) ret += c * (hh[i] - hh[i - 1]);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {
        scanf("%d", h + i);
    }
	for (int i = 2; i <= n; i++) ini += abs(h[i] - h[i - 1]);
	ini *= c;
	sort(h + 1, h + n + 1);
	int lo = h[1], hi = h[n], a, b;
	while (lo < hi) {
	    //printf("%d %d\n", lo, hi);
		a = lo + (hi - lo) / 3;
		b = hi - (hi - lo) / 3;
		if (f(a) > f(b)) {
            ans = b;
            lo = a + 1;
        } else {
            ans = a;
            hi = b - 1;
        }
	}
	ans = f(ans);
	printf("%d %d\n", ans, ini - ans);
}
