#include<cstdio>
#include<cstring>
int t,up1,lo1,up2,lo2;
char c[100];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&c);
        int l=strlen(c);
        int i=1;
        for(; 2*i<=l; i++)
        {
            int j=c[i-1];
            if(j<=122 && j>=97)up1++;
            else lo1++;
        }

        if(l&1)i++;

        for(; i<=l; i++)
        {
            int j=c[i-1];
            if(j<=122 && j>=97)up2++;
            else lo2++;
        }
        if(up1==up2 && lo1==lo2)printf("SI\n");
        else printf("NO\n");

        up1=up2=lo1=lo2=0;
    }
return 0;
}
