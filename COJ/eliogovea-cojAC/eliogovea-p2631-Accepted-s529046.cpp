#include<cstdio>

int c,n;
bool mark[9];
int pass[9],cont;

int fact[9];

void f(int n, int x)
{

    if(x==n+1)
    {
        if(cont==fact[n]/3)
        {
            for(int i=1; i<=n; i++)
                printf("%d",pass[i]);
            printf("\n");
        }
        cont++;
        return;

    }
    for(int i=1; i<=n; i++)
        if(!mark[i])
        {
            mark[i]=1;
            pass[x]=i;
            f(n,x+1);
            mark[i]=0;
        }
}


int main()
{
    fact[0]=1;
    for(int i=1; i<=9; i++)
        fact[i]=i*fact[i-1];



    for(scanf("%d",&c);c--;)
    {
        scanf("%d",&n);
        cont=0;
        f(n,1);
    }
    return 0;
}
