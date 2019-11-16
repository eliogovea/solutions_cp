#include <cstdio>

int d, k, dig[1000005], p;

int main() {
	while (scanf("%d%d", &d, &k) && (d | k)) {
		d *= d;
		int carry = 0;
		p = 0;
		for (int i = 0; i < 2 * k; i++) {
			if (i < k) carry += i + 1;
			else carry += 2 * k - i - 1;
			dig[p++] = carry % 10;
			carry /= 10;
		}
		while (carry) {
			dig[p++] = carry % 10;
			carry /= 10;
		}
		for (int i = 0; i < p; i++) {
			carry += d * dig[i];
			dig[i] = carry % 10;
			carry /= 10;
		}
		while (carry) {
			dig[p++] = carry % 10;
			carry /= 10;
		}
		int sum = 0;
		for (int i = 0; i < p; i++) sum += dig[i];
		printf("%d\n", sum);
	}
}
