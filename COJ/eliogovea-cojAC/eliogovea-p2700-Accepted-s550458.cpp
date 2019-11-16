#include<cstdio>
#define MAXL 30

char word[MAXL];
int w1[MAXL],w2[MAXL];

int main()
{
	scanf("%s", word);

	for(char *p=word; *p; p++)
		w1[*p-'A']=1;

	scanf("%s", word);

	for(char *p=word; *p; p++)
		w2[*p-'A']=1;

	printf("First:");
	for(int i=0; i<26; i++)
		if(w1[i] && !w2[i])
			printf("%c",char(i)+'A');
	printf("\n");

	printf("Second:");
	for(int i=0; i<26; i++)
		if(w2[i] && !w1[i])
			printf("%c",char(i)+'A');
	printf("\n");

	printf("First&Second:");
	for(int i=0; i<26; i++)
		if(w1[i] && w2[i])
			printf("%c",char(i)+'A');
	printf("\n");
}
