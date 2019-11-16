#include <cstdio>
#include <algorithm>
#include <limits>
 
const int N = 200 * 1000 + 10;
 
int t;
int n;
int type[N];
int height[N];
int last[N];
int to_left[N];
 
int top;
int stack[N];
 
long long stree[4 * N];
long long lazy_add[4 * N];
 
void build(int x, int l, int r) {
    stree[x] = 0;
    lazy_add[x] = 0;
    if (l != r) {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
    }
}
 
inline void push(int x, int l, int r) {
    if (lazy_add[x] == 0) {
        return;
    }
    stree[x] += lazy_add[x];
    if (l != r) {
        lazy_add[2 * x] += lazy_add[x];
        lazy_add[2 * x + 1] += lazy_add[x];
    }
    lazy_add[x] = 0;
}
 
void update(int x, int l, int r, int ul, int ur, long long delta) {
    push(x, l, r);
    if (r < ul || ur < l) {
        return;
    }
    if (ul <= l && r <= ur) {
        lazy_add[x] += delta;
        push(x, l, r);
    } else {
        int m = (l + r) >> 1;
        update(2 * x, l, m, ul, ur, delta);
        update(2 * x + 1, m + 1, r, ul, ur, delta);
        stree[x] = std::min(stree[2 * x], stree[2 * x + 1]);
    }
}
 
long long query(int x, int l, int r, int ql, int qr) {
    push(x, l, r);
    if (r < ql || qr < l) {
        return std::numeric_limits<long long>::max();
    }
    if (ql <= l && r <= qr) {
        return stree[x];
    }
    int m = (l + r) >> 1;
    return std::min(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}
 
int main() {
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", type + i, height + i);
        }
 
        for (int i = 1; i <= n; i++) {
            last[type[i]] = 0;
        }
 
        for (int i = 1; i <= n; i++) {
             to_left[i] = std::max(last[type[i]], to_left[i - 1]);
             last[type[i]] = i;
        }
 
        top = 0;
 
        height[0] = std::numeric_limits<int>::max();
        stack[top++] = 0;
 
        build(1, 0, n);
 
        for (int i = 1; i <= n; i++) {
            update(1, 0, n, i - 1, i - 1, height[i]);
            while (height[i] >= height[stack[top - 1]]) {
                int delta = height[i] - height[stack[top - 1]];
                update(1, 0, n, stack[top - 2], stack[top - 1] - 1, delta);
                top--;
            }
            stack[top++] = i;
            long long v = query(1, 0, n, to_left[i], i - 1);
            update(1, 0, n, i, i, v);
        }
 
        printf("Case %d: %lld\n", c, query(1, 0, n, n, n));
    }
}
