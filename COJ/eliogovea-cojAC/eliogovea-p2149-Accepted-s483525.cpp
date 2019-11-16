#include<cstdio>
#include<cstring>
int t,up;
char c[500];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&c);
        int l=strlen(c);
        for(int i=0; i<l; i++)
        {
            int j=c[i];
            if(j<=122 && j>=97)up++;
        }
        if(up==l-up)printf("SI\n");
        else printf("NO\n");

        up=0;
    }
return 0;
}
