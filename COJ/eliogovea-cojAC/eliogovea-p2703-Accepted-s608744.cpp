#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010, mod = 1000000007;

int n, arr[MAXN], sum[MAXN << 2], lazy[MAXN << 2];

void propagate(int idx, int l, int r) {
	if (lazy[idx]) {
		sum[idx] = (sum[idx] + lazy[idx] * (r - l + 1)) % mod;
		if (l != r) {
			lazy[idx << 1]  = (lazy[idx << 1] + lazy[idx]) % mod;
			lazy[(idx << 1) | 1] = (lazy[(idx << 1) | 1] + lazy[idx]) % mod;
		}
		lazy[idx] = 0;
	}
}

void update(int idx, int l, int r, int ul, int ur, int upd) {
	if (l > r) return;
	propagate(idx, l, r);
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		sum[idx] = (sum[idx] + upd * (r - l + 1) % mod) % mod;
		if (l != r) {
			lazy[idx << 1] = (lazy[idx << 1] + upd) % mod;
			lazy[(idx << 1) | 1] = (lazy[(idx << 1) | 1] + upd) % mod;
		}
	}
	else {
		int mid = (l + r) >> 1;
		update(idx << 1, l, mid, ul, ur, upd);
		update((idx << 1) | 1, mid + 1, r, ul, ur, upd);
		sum[idx] = (sum[idx << 1] + sum[(idx << 1) | 1]) % mod;
	}
}

int query(int idx, int l, int r, int ql, int qr) {
	propagate(idx, l, r);
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return sum[idx];
	else {
		int mid = (l + r) >> 1;
		return (query(idx << 1, l, mid, ql, qr) +
				query((idx << 1) | 1, mid + 1, r, ql, qr)) % mod;
	}
}

int main() {
	scanf("%d", &n);
	update(1, 1, n, n, n, 1);
	for (int i = 2; i <= n; i++) {
		scanf("%d", arr + i);
		arr[i] = max(i - arr[i], 1);
	}
	for (int i = n; i > 1; i--) {
		int aux = query(1, 1, n, i, i);
		//printf("%d\n", aux);
		update(1, 1, n, arr[i], i - 1, aux);
		/*for (int i = 1; i <= n; i++)
            printf("%d ", query(1, 1, n, i, i));
        printf("\n");*/
	}
	printf("%d\n", query(1, 1, n, 1, 1));
}
