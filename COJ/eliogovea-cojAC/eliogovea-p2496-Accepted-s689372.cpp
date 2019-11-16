#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000005;

int n, bit[N];

void update(int pos, int val) {
	for (; pos < N; pos = (pos | (pos - 1)) + 1)
        bit[pos] += val;
}

int query(int pos) {
	int ret = 0;
	for (; pos > 0; pos = pos & (pos - 1))
        ret += bit[pos];
	return ret;
}

struct square {
	int x1, y1, x2, y2;
	void read() {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		y1++; y2++;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
	}
	square() {}
} a[N];

struct event {
	int x, id;
	bool in;
	event() {}
	event(int a, int b, bool c) {
		x = a;
		id = b;
		in = c;
	}
	bool operator < (const event &e) const {
		if (x != e.x) return x < e.x;
		if (in && e.in) {
			if (a[id].y1 != a[e.id].y1) return a[id].y1 < a[e.id].y1;
			return a[id].y2 > a[e.id].y2;
		}
		if (!in && !e.in) {
			if (a[id].y1 != a[e.id].y1) return a[id].y1 > a[e.id].y1;
			return a[id].y2 < a[e.id].y2;
		}
		return !in;
	}
} E[N];

int mark[N], ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i].read();
		E[i] = event(a[i].x1, i, 1);
		E[n + i] = event(a[i].x2, i, 0);
	}
	n *= 2;
	sort(E, E + n);
	for (int i = 0; i < n; i++) {
		if (!E[i].in) {
			if (mark[E[i].id]) {
				mark[E[i].id] = 0;
				ans++;
				update(a[E[i].id].y1, -1);
				update(a[E[i].id].y2, 1);
			}
		} else {
			int tmp = query(a[E[i].id].y2);
			if (tmp == 0) {
				mark[E[i].id] = 1;
				update(a[E[i].id].y1, 1);
				update(a[E[i].id].y2, -1);
			}
		}
	}
	printf("%d\n", ans);
}
