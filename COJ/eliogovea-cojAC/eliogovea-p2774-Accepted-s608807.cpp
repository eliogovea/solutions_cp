#include <cstdio>

const int MAXN = 10010;

int f, k, l, v, arr[MAXN], sol;

int main() {
	scanf("%d%d", &f, &k);
	sol = f;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &l, &v);
		for (int i = l; i <= f; i += v) {
			if (arr[i] == 0) sol--;
			arr[i] = 1;
		}
	}
	printf("%d\n", sol);
}
