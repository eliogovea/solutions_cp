#include<cstdio>
#include<cstring>
int n;
double l,lc;
char c[15];

int main()
{
    for(scanf("%d",&n);n--;)
    {
        scanf("%lf",&l);
        sprintf(c,"%.3lf",2.0*l*l/9.0);
        lc=strlen(c);
        for(int i=0; i<lc; i++)
            printf("%c",c[i]=='.'?',':c[i]);
        printf("\n");
    }
    return 0;
}
