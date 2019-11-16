#include <cstdio>

const int MAXN = 40;

int tc, n, f[MAXN][MAXN], aux[MAXN], x, ac;
int sol[MAXN];

int main() {

	for (int i = 2; i < MAXN; i++) {
		for (int j = 2; j < MAXN; j++) f[i][j] = f[i - 1][j];
		int v = i;
		for (int j = 2; j <= v; j++)
			while (v % j == 0) {
				f[i][j]++;
				v /= j;
			}
	}

	for (scanf("%d", &tc); tc--;) {
		ac = 0;
		for (int j = 0; j < MAXN; j++) aux[j] = 0;
		for (int i = 1; i <= 9; i++) {
			scanf("%d", &x);
			for (int j = 2; j < MAXN; j++) aux[j] -= f[x][j];
			ac += x;
		}

		int top = 1;
		for (int i = 0; i < MAXN; i++) sol[i] = 0;
		sol[0] = 1;

		for (int i = 2; i < MAXN; i++) {
			aux[i] += f[ac][i];
			for (int j = 1; j <= aux[i]; j++) {

				int carry = 0;
				for (int k = 0; k < top; k++) {
					carry += sol[k] * i;
					sol[k] = carry % 10;
					carry /= 10;

				}
				while (carry) {
					sol[top++] = carry % 10;
					carry /= 10;
				}
			}
		}
		for (int i = top - 1; i >= 0; i--) printf("%d", sol[i]);
		printf("\n");
	}
}
