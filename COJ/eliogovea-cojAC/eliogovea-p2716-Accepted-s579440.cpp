#include <cstdio>
#include <algorithm>
using namespace std;

int c, n, x, mx, md;

int main()
{
	for (scanf("%d", &c); c--;)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (i && x < mx) md = max(md, mx - x);
			mx = max(mx, x);
		}
		printf("%d\n%d\n", md - md / 2, x + md - md / 2);
		mx = md = 0;
	}
}
