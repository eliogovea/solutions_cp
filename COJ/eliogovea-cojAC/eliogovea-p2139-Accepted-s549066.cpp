#include<cstdio>
#define MAXN 100001

char w1[MAXN],w2[MAXN];

int main()
{
	while(scanf("%s%s",w1,w2)!=EOF)
	{
			char *p1=w1;
			char *p2=w2;
			for(; *p1 && *p2; p2++)
            {
                //printf("%c %c\n",*p1,*p2);
                if(*p1==*p2)
                    p1++;
            }

			if(*p1)printf("No\n");
			else printf("Yes\n");
	}
}
