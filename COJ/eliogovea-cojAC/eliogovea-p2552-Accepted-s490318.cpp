#include<cstdio>

int n,mx,cm,x,t,smx;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        t+=x;
        if(x>mx)
        {
            smx=mx;
            mx=x;
        }
        else if(x>smx)smx=x;
    }

    if(mx>smx)
    {
        double MX=(double)mx,T=(double)t,SMX=(double)smx;
        if(MX>=9.0*T/20.0)printf("1\n");
        else if(MX>=2.0*T/5.0 && MX>=SMX+T/10.0)printf("1\n");
        else printf("2\n");
    }
    else printf("2\n");

    return 0;

}
