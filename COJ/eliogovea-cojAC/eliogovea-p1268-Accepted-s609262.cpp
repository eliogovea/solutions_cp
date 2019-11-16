#include <cstdio>
using namespace std;

int n;

bool primo(int n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	if (n == 1) printf("YES\n");
	else if (n == 4) printf("NO\n");
	else printf("%s\n", primo(n) ? "NO" : "YES");
}