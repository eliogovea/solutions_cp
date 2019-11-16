#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 100000;

int n, a[MAXN + 10], sol;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
		sol = max(sol, a[i] + i + 1);
	printf("%d\n", sol);
}
