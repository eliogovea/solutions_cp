#include <cstdio>

char str[1010];
int s1, s2;

int main()
{
	scanf("%s", str);
	for (char *p = str; *p; p++)
	{
		if (*p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') s1++;
		else s2++;
	}
	printf("%d %d\n", s1, s2);
}
