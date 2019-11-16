#include <cstdio>

const int MAXN = 100010;

char n[MAXN];
int b, d;

int main() {
	scanf("%s%d%d", n, &b, &d);
	int res = 0;
	for (char *p = n; *p; p++)
		res = (b * res + (*p - '0') % d) % d;
	printf("%s\n", (res == 0) ? "YES" : "NO");
}
