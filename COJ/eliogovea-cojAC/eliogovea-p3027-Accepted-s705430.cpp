#include <cstdio>

const int N = 1000005;

typedef long long LL;

char s[N], let[2];
LL n, m, k, f, sz;
LL ac['Z' - 'A' + 15][N];

int main() {
    scanf("%lld%s%lld", &n, s, &m);
	for (int i = 0; s[i]; i++) {
        sz = i;
		if (i != 0)
			for (int j = 'A'; j <= 'Z'; j++)
				ac[j - 'A' + 1][i] = ac[j - 'A' + 1][i - 1];
		ac[s[i] - 'A' + 1][i]++;
	}
	sz++;
	while (m--) {
		scanf("%lld%s", &f, let);
		char c = let[0];
		c = c - 'A' + 1;
		LL a = f - 1LL, b = f;
		if (a % 2LL == 0LL) a /= 2LL;
		else b /= 2LL;
        a %= sz;
        b %= sz;
        LL lo = (a * b) % sz;
        if (lo == 0LL) lo = sz - 1LL;
        else lo--;

        LL ret;

        if (f < sz - 1LL - lo) {
            LL hi = (lo + (f % sz)) % sz;
            ret = ac[c][hi] - ac[c][lo];
        } else {
            ret = ac[c][sz - 1] - ac[c][lo];
            f -= (sz - 1LL - lo);
            ret += ac[c][sz - 1] * (f / sz);
            f %= sz;
            if (f != 0LL) ret += ac[c][f - 1LL];
        }
		printf("%lld\n", ret);
	}
}
