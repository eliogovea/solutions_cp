#include <cstdio>

const int MAXN = 500;

int n, sol;
bool sq[MAXN * MAXN + 10];

int main() {
	for (int i = 1; i <= MAXN; i++) sq[i * i] = 1;
	scanf("%d", &n);
	for (int i = 1; i + n <= MAXN * MAXN; i++)
		sol += (sq[i] & sq[i + n]);
	printf("%d\n", sol);
}
