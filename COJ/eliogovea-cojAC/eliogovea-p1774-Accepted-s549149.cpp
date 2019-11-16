#include<cstdio>
#define MAXN 110

char word[MAXN];
int low,up;

char change(char c)
{
	if(c>='a' && c<='z')
		return c-'a'+'A';
	else return c+'a'-'A';
}

int main()
{
	scanf("%s",word);

	for(char *p=word; *p; p++)
		if(*p>='a' && *p<='z')low++;
		else up++;

	if(!up)printf("%s\n",word);

	else if(up==1 && word[0]>='A' && word[0]<='Z')printf("%s\n",word);

	else for(char *p=word; *p; p++)
            printf("%c",change(*p));
}
