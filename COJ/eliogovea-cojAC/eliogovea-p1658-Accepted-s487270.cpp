#include<cstdio>

int c,n,a[1000],l[1000],MAX;

int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&a[i]);

        for(int i=0; i<n; i++)l[i]=1;

        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(a[i]>a[j] && l[i]<l[j]+1)
                    l[i]=l[j]+1;

        for(int i=0; i<n; i++)
            if(MAX<l[i])MAX=l[i];

        printf("%d\n",MAX);

        MAX=0;
    }
return 0;
}
