#include <cstdio>

const int MAXN = 500;

int n, m, a, b, c, ans;
int arr[MAXN + 10];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a) {
			ans = 0;
			for (int i = b; i <= c; i++)
				ans += arr[i];
			printf("%d\n", ans);
		}
		else for (int i = b; i <= c; i++) arr[i] ^= 1;
	}
}
