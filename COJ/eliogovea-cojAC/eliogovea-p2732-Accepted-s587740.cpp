#include <cstdio>
#include <algorithm>
using namespace std;

int n;
char str[1000010];

int main()
{
	for (scanf("%d", &n); n--;)
	{
		scanf("%s", str);
		for (char *p = str; *p; p++)
			if (*p <= 'Z') printf("%c", *p - 'A' + 'a');
			else printf("%c", *p - 'a' + 'A');
        printf("\n");
	}
}
