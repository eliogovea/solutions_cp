#include <cstdio>
#include <map>

using namespace std;

typedef long long LL;

const int N = 2005;

int n;
LL X1[N], X2[N], Y1[N], Y2[N];
LL a[N], b[N], c[N];

inline LL abs(LL n) {
    if (n < 0) n = -n;
    return n;
}

// (a, b) -> (b, a % b)
inline LL gcd(LL a, LL b) {
	LL tmp;
	while (b) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

struct data {
	LL a, b;
	LL n, d;
};

bool operator < (const data &a, const data &b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	if (a.n != b.n) return a.n < b.n;
	return a.d < b.d;
}

map <data, int> M;
map <data, int>::iterator it;

data tmp;
LL dx, dy, num, den, aa, bb, g;

int main() {
	//freopen("dat.txt", "r", stdin);
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld%lld", X1 + i, Y1 + i, X2 + i, Y2 + i);
		dx = X2[i] - X1[i];
		dy = Y2[i] - Y1[i];
		a[i] = dy;
		b[i] = -dx;
		c[i] = a[i] * X1[i] + b[i] * Y1[i];
		g = gcd(abs(a[i]), gcd(abs(b[i]), abs(c[i])));
		if (g != 0) {
			a[i] /= g;
			b[i] /= g;
			c[i] /= g;
		}
		if (a[i] < 0) {
			a[i] = -a[i]; b[i] = -b[i]; c[i] = -c[i];
		} else if (a[i] == 0) {
			if (b[i] < 0) {
				b[i] = -b[i]; c[i] = -c[i];
			} else if (b[i] == 0) {
				if (c[i] < 0) {
					c[i] = -c[i];
				}
			}
		}
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j] && b[i] == b[j]) {
				num = abs(c[i] - c[j]);
				den = a[i] * a[i] + b[i] * b[i];
				g = gcd(num, den);
				if (g != 0) {
					num /= g;
					den /= g;
				}

				aa = -b[i];
				bb = a[i];
				if (aa < 0) {
					aa = -aa; bb = -bb;
				} else if (a == 0) {
					if (bb < 0) {
						bb = -bb;
					}
				}
				tmp.a = aa;
				tmp.b = bb;
				tmp.n = num;
				tmp.d = den;
				it = M.find(tmp);
				if (it != M.end()) {
					ans += it->second;
				}
				tmp.a = a[i];
				tmp.b = b[i];
				tmp.n = num;
				tmp.d = den;
				M[tmp]++;
			}
		}
	}
	printf("%lld\n", ans);
}
