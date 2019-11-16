// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 2 (ASC 2)
// 100197C

#include <cstdio>
#include <queue>

using namespace std;

struct node {
    int l, r;
    long long val;
    int pos;
};

bool operator < (const node &a, const node &b) {
    return a.val > b.val;
}

const int N = 500005;

int n, a[N];

node tree[2 * N];
int sz = 0;


priority_queue<node> q;

void build() {
    for (int i = 1; i <= n; i++) {
        q.push((node) {-1, -1, a[i], -1});
    }
    node x, y;
    while (q.size() >= 2) {
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        x.pos = sz;
        tree[sz++] = x;
        y.pos = sz;
        tree[sz++] = y;
        q.push((node) {x.pos, y.pos, x.val + y.val, -1});
    }
    x = q.top(); q.pop();
    tree[sz++] = x;
}

long long ans;

int d[2 * N];

int main() {
    //freopen("dat.txt", "r", stdin);
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build();
        for (int i = sz; i >= 0; i--) {
            if (tree[i].l != -1) {
                d[tree[i].l] = d[i] + 1;
                d[tree[i].r] = d[i] + 1;
            } else {
                ans += tree[i].val * d[i];
            }
        }
    printf("%I64d\n", ans);
}
