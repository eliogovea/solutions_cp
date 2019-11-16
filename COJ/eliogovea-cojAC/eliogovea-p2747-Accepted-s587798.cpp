#include <cstdio>
#include <map>
using namespace std;

int n, a[5010], sol;
map<int, int> m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = i - 1; j >= 0; j--)
			if (m[a[i] - a[j]])
			{
				sol++;
				break;
			}
		for (int j = i; j >= 0; j--)
			m[a[i] + a[j]] = 1;
	}
	printf("%d\n", sol);
}
