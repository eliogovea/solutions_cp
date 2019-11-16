#include<cstdio>
#include<cstring>

int r,i,j,ci,cj,la,lb,m,x,cri,crj;
char a[1000],b[1000];

int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    scanf("%d%s%s",&r,&a,&b);

    la=strlen(a);
    lb=strlen(b);

    m=la*lb/gcd(la,lb);
    x=r%m;

    if(r<=m)
    {
        for(int k=1; k<=r ; k++)
        {
            if(a[i]=='R' && b[j]=='S')cj++;
            else if(a[i]=='R' && b[j]=='P')ci++;
            else if(a[i]=='S' && b[j]=='R')ci++;
            else if(a[i]=='S' && b[j]=='P')cj++;
            else if(a[i]=='P' && b[j]=='S')ci++;
            else if(a[i]=='P' && b[j]=='R')cj++;

            if(i<la-1)i++;
            else i=0;
            if(j<lb-1)j++;
            else j=0;
        }
    printf("%d %d\n",ci,cj);
    }

    else if(r>m)
    {
        for(int k=0; k<m; k++)
        {
            if(k==x)
            {
                cri=ci;
                crj=cj;
            }
            if(a[i]=='R' && b[j]=='S')cj++;
            else if(a[i]=='R' && b[j]=='P')ci++;
            else if(a[i]=='S' && b[j]=='R')ci++;
            else if(a[i]=='S' && b[j]=='P')cj++;
            else if(a[i]=='P' && b[j]=='S')ci++;
            else if(a[i]=='P' && b[j]=='R')cj++;

            if(i<la-1)i++;
            else i=0;
            if(j<lb-1)j++;
            else j=0;
        }
    printf("%d %d\n",ci*((int)r/m)+cri,cj*((int)r/m)+crj);
    }
    return 0;
}
