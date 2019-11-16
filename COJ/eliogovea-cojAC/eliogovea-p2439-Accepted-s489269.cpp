#include<cstdio>
#include<cmath>

int c,l,t;
int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&l,&t);
        printf("%d\n",(int)(log((double)t/(double)l)/log(5.0/3.0)));
    }
    return 0;
}
