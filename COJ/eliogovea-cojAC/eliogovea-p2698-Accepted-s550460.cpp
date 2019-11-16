#include<cstdio>
#define MAXL 30

char word[MAXL];
int sol;

int main()
{
	scanf("%s", word);

	for(char *p=word; *p; p++)
		sol+=*p-'A'+1;
	printf("%d\n",sol);
}
