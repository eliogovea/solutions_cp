#include<cstdio>

int n;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int count=0;
        while(n%2==0)
        {
            count++;
            n/=2;
        }

        if(count)printf("(%d(%d))",2,count);
        for(int i=3; i*i<=n; i+=2)
        {
            count=0;
            while(n%i==0)
            {
                count++;
                n/=i;
            }
            if(count)printf("(%d(%d))",i,count);
        }
        if(n>1)printf("(%d(1))",n);
        printf("\n");
    }
    return 0;
}
