#include<cstdio>
#include<cmath>
int n,a,b,ma,mb;
double m,aux;

int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            aux=(double)b*log(a);
            if(aux>m)
            {
                m=aux;
                ma=a;
                mb=b;
            }
        }
    printf("%d %d\n",ma,mb);
    
    m=0;
    }
return 0;
}
