#include <cstdio>

long long n, b[105];

int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", b + i);
		printf("%lld%c", i * b[i] - (i - 1) * b[i - 1], (i != n) ? ' ' : '\n');
	}
}
