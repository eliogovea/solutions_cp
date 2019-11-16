#include<cstdio>

int h,m,k;

int main()
{
    scanf("%d%d%d",&m,&h,&k);

    int sob = m-2*h;

    while(k>0)
    {
        while(m>2*h)m--,k--;
        if(k<=0)break;
        while(m<2*h)h--,k--;
        if(k<=0)break;
        h--;
        m-=2;
        k-=3;
    }

    //printf("%d %d\n",h,m);

    if(m==2*h)printf("%d\n",h);
    else printf("%d\n",m/2);

    return 0;
}
