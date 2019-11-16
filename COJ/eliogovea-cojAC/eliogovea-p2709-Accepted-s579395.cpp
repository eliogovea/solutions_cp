#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int n, p, x;
bool mark[MAXN];

int main()
{
	scanf( "%d%d", &n, &p );
	for (int i = 0; i < p; i++)
	{
		scanf("%d", &x);
		if (!mark[x]) n--;
		mark[x] = 1;
	}
	printf ("%d\n", n);
}
