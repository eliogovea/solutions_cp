#include <cstdio>

const int MAXN = 1000000;

int tc, n, div[MAXN + 5], sol[MAXN + 5];

int main() {
  //freopen("e.in", "r", stdin);
	for (int i = 1; i <= MAXN; i++)
		for (int j = i; j <= MAXN; j += i)
			div[j]++;
  int mx = 0;
  for (int i = 1; i <= MAXN; i++) {
    if (div[mx] < div[i]) mx = i;
    sol[i] = mx;
  }
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    printf("%d\n", sol[n]);
  }
}
