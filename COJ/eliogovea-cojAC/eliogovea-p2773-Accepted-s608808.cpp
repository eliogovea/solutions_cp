#include <cstdio>

int a, b, c, f[100], id;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++) {
				f[i + j + k]++;
				if (f[i + j + k] > f[id]) id = i + j + k;
			}
	printf("%d\n", id);
}
