#include <cstdio>
using namespace std;

int n, a[50], b[50];


int main()
{
	scanf("%d", &n);
	a[0] = 1;   b[0] = 0;
	a[1] = 0;   b[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	printf("%d %d\n", a[n], b[n]);
}
