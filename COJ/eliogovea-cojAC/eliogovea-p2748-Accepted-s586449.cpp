#include <cstdio>
#include <algorithm>
using namespace std;

int n, x, y, sol;

int main()
{
	for (scanf("%d", &n); n--;)
	{
		scanf("%d%d", &x, &y);
		sol = max(sol, x * x + y * y);
	}
	printf("%d\n", sol);
}
