#include <cstdio>

const int MAXN = 100000;

int n, sd[MAXN + 10], sol[MAXN + 10];

int SD(int n) {
	if (n <= MAXN) return sd[n];
	return n % 10 + SD(n / 10);
}

int main() {
	for (int i = 1; i <= MAXN; i++)
		sd[i] = i % 10 + sd[i / 10];
	for (int i = 1; i <= MAXN; i++)
		for (int j = 11; j <= 100; j++)
			if (SD(i) == SD(i * j)) {
				sol[i] = j;
				break;
			}
	while (scanf("%d", &n) && n) printf("%d\n", sol[n]);
}
