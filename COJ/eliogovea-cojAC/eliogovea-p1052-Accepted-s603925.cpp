#include <cstdio>

int n;

bool p(int n) {
	if (n == 0 || n == 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (!(n & 1)) return 0;
	for (int i = 3; i * i <= n; i += 2)
		if (!(n % i)) return 0;
	return 1;
}

void f(int td, int d, int num) {
	if (p(num) == false && num) return;
	if (d == td) {
		printf("%d\n", num);
	}
	else for (int i = 1; i <= 9; i++) f(td, d + 1, 10 * num + i);
}

int main() {
    while (scanf("%d", &n) == 1) f(n, 0, 0);
}
