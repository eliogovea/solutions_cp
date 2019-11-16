#include<cstdio>

bool s[101];
int n,k,m,p,c,nm,x;

int main()
{
    for(int i=2; i<=100; i++)s[i]=1;
    for(int i=2; i*i<=100; i++)
        if(s[i])for(int j=i*i; j<=100; j+=i)s[j]=0;

    scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++)
    {
        c=0;
        for(int j=1; j<=k; j++)
        {
            scanf("%d",&x);
            if(s[x])c++;
        }
        if(c==m)nm++;
        else if(c>m)
        {
            m=c;
            nm=1;
            p=i;
        }
    }

    if(nm>1)printf("No winner");
    else printf("Object %d wins with %d rare characteristics",p,m);

    return 0;
}
