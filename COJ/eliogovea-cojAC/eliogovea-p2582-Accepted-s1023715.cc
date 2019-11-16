#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

typedef long long ll;

struct rect {
	int w, h;
};

bool operator < (const rect &a, const rect &b) {
	if (a.w != b.w) return a.w < b.w;
	return a.h > b.h;
}

//////
bool query_flag = false;
struct line {
  long long m, c;
  mutable function<const line*()> succ;
  bool operator<(const line& o) const {
    if (!query_flag) return m > o.m;
    const line* s = succ();
    if (!s) return false;
    return (c - s->c) > (s->m - m) * o.m;
  }
};

struct maximum_hull : multiset<line> {
  bool bad(iterator y) {
    auto x = (y == begin()) ? end() : prev(y), z = next(y);
    if (x == end() && z == end()) return false;
    else if (x == end()) return y->m == z->m && y->c <= z->c;
    else if (z == end()) return y->m == x->m && y->c <= x->c;
    else return (x->c - y->c) * (z->m - y->m) >= (y->c - z->c) * (y->m - x->m);
  }
  void insert_line(const long long& m, const long long& c) {
    auto y = insert({ m, c, nullptr });
    y->succ = [=] { return next(y) == end() ? nullptr : &*next(y); };
    if (bad(y)) { erase(y); return; }
    iterator z;
    while ((z = next(y)) != end() && bad(z)) erase(z);
    while (y != begin() && bad(z = prev(y))) erase(z);
  }
  long long eval(long long x) {
    if (empty()) return numeric_limits<ll>::min();
    query_flag = true;
    auto l = *lower_bound({ x, 0, nullptr });
    query_flag = false;
    return l.m * x + l.c;
  }
} CH;

int n;
rect a[N];
long long dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].w >> a[i].h;
	}
	sort(a, a + n);
	int top = 0;
	for (int i = 0; i < n; i++) {
		while (top > 0 && a[i].h >= a[top - 1].h) {
			top--;
		}
		a[top++] = a[i];
	}
	CH.insert_line(a[0].h, 0);
	for (int i = 0; i < top; i++) {
		dp[i] = CH.eval(a[i].w);
		CH.insert_line(a[i + 1].h, dp[i]);
	}
	cout << dp[top - 1] << "\n";
}
